### OpenGL Coordinate Systems – Short Note

OpenGL transforms object vertices through multiple coordinate systems before they appear on screen. Each space serves a purpose:

1. **Local Space (Object Space)**

   * Vertex coordinates relative to the object’s own origin.
   * Example: a cube created in Blender with origin at (0,0,0).
   * Transformations here affect the object itself (scaling, rotation).

2. **World Space**

   * Vertices positioned relative to a global origin, representing the “scene”.
   * Achieved via the **model matrix**: translates, rotates, and scales objects into their place in the world.

3. **View Space (Eye/Camera Space)**

   * Vertices transformed as seen from the camera.
   * Achieved via the **view matrix**: moves and rotates the scene so the camera sees the correct part.

4. **Clip Space**

   * Vertices transformed to a range where OpenGL can determine visibility (-1.0 to 1.0 after **perspective division**).
   * Achieved via the **projection matrix**, which can be:

     * **Orthographic**: straight mapping, no perspective; good for 2D or engineering apps.
     * **Perspective**: simulates realistic depth; objects farther away appear smaller.
   * Perspective division divides x, y, z by w to map coordinates to **Normalized Device Coordinates (NDC)**.

5. **Screen Space**

   * Maps NDC to actual pixels using `glViewport`.
   * The rasterizer converts these coordinates to fragments that appear on screen.

**Full Transformation Pipeline**:

[
V_{clip} = M_{projection} \cdot M_{view} \cdot M_{model} \cdot V_{local}
]

* Right-to-left multiplication: local → model → view → projection → clip → NDC → screen.
* Each matrix isolates a type of transformation for flexibility.

**Key Takeaways**:

* Transform vertices step-by-step for flexibility and easier calculations.
* Local transformations affect the object; world transformations affect placement in the scene; view transforms simulate the camera; projection transforms map to NDC; viewport maps to screen pixels.
* Use orthographic projection for 2D or exact measurements, perspective projection for realistic 3D visuals.
