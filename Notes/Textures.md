### Textures and Geometry: One Continuous Flow

Vertices carry more than positions—they carry **attributes** like texture coordinates `(u, v)`. These attributes travel **together** with positions through the pipeline.

The uv cords help in mapping the texture to the triangle

* Vertex shader: computes `gl_Position` (clip → NDC) and passes `u, v` along.
* Rasterization: generates fragments inside triangles, using **barycentric coordinates** to interpolate all vertex attributes—including texture coordinates.

But linear interpolation in screen space would break textures under perspective. This is where the fourth component `w` matters. The GPU performs **perspective-correct interpolation**:

```
interpolate u/w, v/w, 1/w → reconstruct u_corrected = (u/w)/(1/w)
```

Result: textures shrink and stretch **exactly like geometry**, appearing “glued” to surfaces.

**Pipeline in one breath:**

1. Vertices carry positions + UVs
2. Projection computes `w`
3. Perspective divide scales geometry
4. Rasterizer interpolates attributes using `w`
5. Fragment shader samples texture with corrected UVs

Textures aren’t pasted on—they are **mathematical coordinates that flow through the same rules as geometry**. Perspective makes them behave correctly; without `w`, they’d slide, stretch, or warp.

---

If you want, I can also make an **even shorter, mental-model version** that fits on a single page as a “textures + perspective cheat sheet” for fast recall. This would be ideal for quick pipeline intuition. Do you want me to do that?
