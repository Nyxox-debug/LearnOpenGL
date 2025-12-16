## 1. Why shaders start with version, inputs/outputs, uniforms, then `main`

A shader is not a script that runs top-to-bottom like C or Python. It’s more like a **contract** the GPU must understand *before* execution.

So GLSL enforces a structure:

1. **Version declaration**

   ```glsl
   #version 330 core
   ```

   This tells the compiler *which language rules to use*.
   Without it, the compiler doesn’t know how to interpret the rest.

2. **Interface declarations**

   ```glsl
   in vec3 aPos;
   out vec4 FragColor;
   uniform vec4 ourColor;
   ```

   These are **communication ports**:

   * `in` → data coming *into* this shader stage
   * `out` → data going *out* to the next stage or framebuffer
   * `uniform` → constant data supplied by the CPU

   The GPU must know all of this **before execution begins**, so these come first.

3. **`main()`**

   ```glsl
   void main() {
       FragColor = ourColor;
   }
   ```

   This is the executable logic that runs per vertex or per fragment.

So the order isn’t stylistic—it’s about declaring the interface before running the logic.

---

## 2. What `glGetUniformLocation` is really doing

Uniforms live **inside a linked shader program** on the GPU.
But the CPU can’t access them by name directly.

So this call exists:

```cpp
int location = glGetUniformLocation(shaderProgram, "ourColor");
```

This asks the GPU:

> “Inside *this linked program*, where did you place the uniform called `ourColor`?”

The GPU answers with:

* a **location index** (like `3`, `7`, etc.), or
* `-1` if it doesn’t exist

### Why would it return `-1`?

Common reasons:

* The name is misspelled
* The uniform was **optimized out** (declared but never used)
* The program wasn’t linked successfully

This is not an error—just information.

---

## 3. Why you don’t need `glUseProgram` to *query* uniforms

This part confuses many people, so here’s the clean mental rule:

* **Querying** → asks questions about a program
* **Updating** → modifies the *currently active* program

So:

```cpp
glGetUniformLocation(program, "ourColor");
```

Works without `glUseProgram` because:

* You’re asking about a specific program object
* Nothing is being changed

Think of it like reading a book title from a shelf—you don’t need to open the book.

---

## 4. Why `glUseProgram` *is required* to set uniforms

Now this line:

```cpp
glUniform4f(location, r, g, b, a);
```

This does **not** specify *which* program to update.

Instead, OpenGL assumes:

> “Apply this uniform change to the currently active shader program.”

So you must do:

```cpp
glUseProgram(program);
glUniform4f(location, r, g, b, a);
```

Otherwise:

* The uniform is sent to the *wrong program*, or
* Nothing happens at all

This design is very OpenGL-ish: **state-based, implicit, fast, unforgiving**.

---

## 5. The full flow, mentally simplified

1. Write shader → compile → link → program lives on GPU
2. Ask GPU: “Where is uniform X in this program?”
3. Activate the program
4. Send uniform data into the active program
5. Draw

If you mix up steps 2 and 4, things silently fail.

---

## The deeper pattern to notice

You’re seeing a recurring OpenGL rule:

* **Reflection** (querying locations) is program-specific
* **Mutation** (setting values) is state-based and affects the active object

This exact rule repeats with:

* attributes
* uniforms
* textures
* framebuffers
