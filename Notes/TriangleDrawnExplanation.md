This is where OpenGL moves from “raw points in space” to actual shapes on the screen. Let’s break it down **step by step**:

---

## 1. Linking vertices → triangles

The GPU **doesn’t magically know** what to connect; it’s told explicitly by the **draw call** and the **primitive type**.

```cpp
glDrawArrays(GL_TRIANGLES, 0, 3);
```

* `GL_TRIANGLES` → tells OpenGL: “Every group of 3 consecutive vertices makes one triangle.”
* `0` → start at the first vertex in the buffer
* `3` → take 3 vertices

So in your example:

| Vertex | Position      | Color   |
| ------ | ------------- | ------- |
| 0      | 0.5, -0.5, 0  | 1, 0, 0 |
| 1      | -0.5, -0.5, 0 | 0, 1, 0 |
| 2      | 0.0, 0.5, 0   | 0, 0, 1 |

* Triangle = vertices 0 → 1 → 2
* The order matters; this is called **winding order** (default: counter-clockwise = front face)

---

### Other ways to link vertices

You could also use **indexed drawing** with an **Element Buffer Object (EBO/IBO)**:

```cpp
unsigned int indices[] = { 0, 1, 2 };
glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
```

* This lets you **reuse vertices** for multiple triangles without duplicating data.
* For a square made of 2 triangles, you’d only need 4 vertices and 6 indices.

---

## 2. Filling inside the triangle → Rasterization

Once the GPU knows the triangle corners, the **rasterizer** takes over:

* The triangle is projected to **screen space** (after vertex shader + transformations)
* Rasterization calculates **which pixels (fragments) are inside the triangle**
* Each pixel gets a **fractional weight for each vertex** called **barycentric coordinates**
* These weights are used to **interpolate vertex attributes** like color, normals, texture coordinates

Example:

```
Vertices: A(red), B(green), C(blue)

Pixel P inside triangle → compute weights (α, β, γ)
Color(P) = α*red + β*green + γ*blue
```

This is why your triangle smoothly blends the three vertex colors.

---

### Mental pipeline:

```
Vertex Buffer (positions + colors)
        ↓
Vertex Shader (maybe transforms positions)
        ↓
Primitive Assembly → groups of vertices into triangles
        ↓
Rasterization → figure out which pixels are covered by the triangle
        ↓
Fragment Shader → calculate final pixel color (interpolated from vertices)
        ↓
Framebuffer → displayed on screen
```

---

If you want, I can **draw a little diagram showing a triangle with vertices, the interpolation inside it, and how the pixels get colors**—it makes this concept really click visually.

Do you want me to make that diagram?
