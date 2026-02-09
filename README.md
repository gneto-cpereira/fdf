# 🌐 FdF

FdF is a minimalist 3D wireframe renderer written in C. It transforms coordinates from a simple text file into a 3D isometric representation. This project focuses on graphic rendering algorithms, mathematical projections, and window management.

## 🚀 How to compile it
### Prerequisites
- Docker installed.
### Commands
```bash
git clone https://github.com/gneto-cpereira/fdf.git
cd fdf
./run.sh
```
A menu will open where you can select a map to view.

### Interactive Launcher
I developed a Bash Wrapper Script that handles the Docker build and provides an interactive menu to choose your map:

![fdf-v1](https://github.com/user-attachments/assets/a08c1d59-0c7d-4df6-8e2e-d61e4e80ba87)
![fdf-v2](https://github.com/user-attachments/assets/9680c303-5c03-46cf-8b0a-c057edc87f90)


## 🛠️ Skills & Technical Knowledge

### 💻 C Programming & Memory Management
* **C Development:** Written in C following strict compilation standards (**-Wall -Wextra -Werror**) for code stability.
* **Memory Safety:** Manual management of the heap and stack, ensuring no memory leaks through **Valgrind** testing.
* **Error Handling:** Implementation of exit protocols for file descriptors, memory allocation failures, and invalid inputs.

### 📐 Computer Graphics & Mathematics
* **Line Rendering:** Implementation of the **Bresenham’s Line Algorithm** to render vectors.
* **Projections:** Conversion of 3D data points into **Isometric** 2D coordinates using trigonometric functions.
* **Event Handling:** Management of window hooks and keyboard inputs for real-time interaction via **MiniLibX**.

### 🏗️ Build Systems & DevOps
* **Incremental Compilation:** Optimized **Makefiles** that only recompile modified files, improving development speed.
* **Containerization:** Use of **Docker** (Ubuntu 22.04) to provide a consistent environment and handle all X11 dependencies.
* **Automation:** **Bash scripting** to automate the build process and provide a simple command-line interface for the user.

### 🧩 Data Parsing
* **File Parsing:** Logic to read and validate `.fdf` files, converting text-based coordinates into internal data structures.

## 🖼️ Samples

### Rotation
![fdf-v3](https://github.com/user-attachments/assets/658b833f-3ab0-4723-997f-a28396307470)

### Z-scaling
![fdf-v5](https://github.com/user-attachments/assets/f83eb117-30ba-452d-ba3a-27350edbf804)

### Terrain Simulation
![fdf-v4](https://github.com/user-attachments/assets/4b9c5d19-2da7-477d-9dc9-744962f31efb)

