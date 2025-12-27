# The-Liang-Barsky-Line-Clipping-Program-C-



````markdown
# Liang-Barsky Line Clipping Visualization in C

This repository contains a **C program** that demonstrates the **Liang–Barsky line clipping algorithm** using **OpenGL** and **GLUT**. It visually shows how a line is clipped against a rectangular window.

---

## Features

- Displays:
  - Clipping window (white rectangle)
  - Original line (red)
  - Clipped line (green)
- Handles lines partially or fully outside the clipping window
- Easy to compile and run on Linux

---

## Prerequisites

Make sure you have **OpenGL** and **GLUT** installed:

```bash
sudo apt update
sudo apt install freeglut3 freeglut3-dev
````

---

## Usage

### 1. Save the Code

Save the code as `liang_barsky_visual.c`.

### 2. Compile

Use this exact command:

```bash
gcc liang_barsky_visual.c -o liang_barsky_visual -lglut -lGLU -lGL
```

> ⚠️ **Order matters:** `-lglut -lGLU -lGL`.

### 3. Run

```bash
./liang_barsky_visual
```

---

## Expected Output

* ⬜ White rectangle → Clipping window
* 🟥 Red line → Original line
* 🟩 Green line → Clipped line

This confirms that the **Liang–Barsky algorithm works visually**.

---

## Common Issues & Fixes

### 1. `warning: built-in function ‘y1’ declared as non-function`

**Cause:** `y1` is a reserved math function in C.
**Fix:** Rename variables like this:

```c
float x_start = 20, y_start = 20;
float x_end   = 100, y_end   = 80;
```

---

### 2. Undefined reference errors (`glColor3f`, `glBegin`, `glutInit`, etc.)

**Cause:** Missing OpenGL libraries or wrong linking order.
**Fix:** Install libraries (see prerequisites) and use the correct compilation order.

---

## Optional Enhancements

* Add **step-by-step animation**
* Add **keyboard control**
* Create **exam-ready documentation**

---

## License

This project is **open-source**. Feel free to use, modify, and share.

