A **right-handed system** is a way of defining the orientation of the 3D coordinate axes. It tells you how the x, y, and z axes relate to each other in 3D space.

---

### How it works:

1. Imagine your **right hand**.
2. Point your **thumb** along the **x-axis**.
3. Point your **index finger** along the **y-axis**.
4. Your **middle finger**, sticking out perpendicular to your palm, points along the **z-axis**.

The axes follow this rule:

[
\text{X × Y = Z}
]

* “×” here is the **cross product**. If you take a vector along X and cross it with a vector along Y, you get a vector along Z.
* This ensures the coordinate system is **right-handed**.

---

### Why it matters in OpenGL:

* OpenGL uses a **right-handed coordinate system** by default.

  * Positive X → right
  * Positive Y → up
  * Positive Z → **toward you** (out of the screen)
* This affects how rotations, camera views, and transformations behave.
* Switching to a **left-handed system** (used in DirectX by default) flips the Z-axis direction.

---
