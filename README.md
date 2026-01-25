## OpenGL Learning Journey

This repository documents my hands-on journey learning **OpenGL**, following the excellent guide at
[learnopengl.com](https://learnopengl.com/).

I started from the **Getting Started** section and progress topic by topic, focusing on understanding what’s happening under the hood rather than just making things render.

### Branch Structure

Each major topic or chapter is developed on its own branch.
Switch branches depending on the concept you’re exploring or reviewing.

### Project Layout Notes

* **Shaders**

  * The `shaders/` directory is expected to live inside the **build directory**.
  * Shader paths are configured to be **relative to the executable**, which is generated in `build/`.
  * The folder is kept outside `build/` in the repository so it can be tracked by Git—copy it into `build/` before running.

* **Resources / Models**

  * When you reach the **model loading** section, the `resources/` directory should also be placed inside the `build/` directory.
  * This folder is **not tracked by Git** due to its size.

### Milestone

Below is a snapshot from the point where I successfully loaded and rendered a 3D model using OpenGL:

![Model loaded successfully](docs/ModelLoading.png)

This marks a key step in the journey—from basic primitives to real assets, meshes, and textures.

### Goal

This isn’t a polished engine or framework.
It’s a learning log: experiments, mistakes, fixes, and gradual understanding built while working through modern OpenGL.
