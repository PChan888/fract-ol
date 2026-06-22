*This project has been created as part of the 42 curriculum by kai.*

## Description

Fract'ol is a small fractal exploration program built with the school's MiniLibX
graphics library. It renders the Mandelbrot set, the Julia set, and the Burning
Ship fractal, using complex-number iteration and smooth HSV-based coloring to
reveal the depth of each set. The view can be explored interactively: the mouse
wheel zooms in and out centered on the cursor, and the arrow keys pan the view.

## Instructions

### Compilation

```
make
```

This builds `Libft` and `minilibx-linux` first, then compiles and links the `fractol` binary. Other available rules: `clean`, `fclean`, `re`.

### Execution

```
./fractol mandelbrot
./fractol julia <re> <im>
./fractol burning_ship
```

- `mandelbrot` — renders the Mandelbrot set.
- `julia <re> <im>` — renders the Julia set for the complex constant `re + im*i` (e.g. `./fractol julia 0.285 0.01`).
- `burning_ship` — renders the Burning Ship fractal.

If no argument or an invalid argument is given, the program prints the usage list above and exits.

### Controls

- **Mouse wheel** — zoom in/out, centered on the cursor position.
- **Arrow keys** — pan the view.
- **ESC** or the window's close button — quit cleanly.

## Resources

- [Youtube: Numberphile - What's so special about the Mandelbrot Set?](https://www.youtube.com/watch?v=FFftmWSzgmk)
- [Youtube: The Mathemagicians' Guild - Julia sets](https://www.youtube.com/watch?v=dctJ7ISkU-4&t=1s)
- [MiniLibX documentaion](https://qst0.github.io/ft_libgfx/man_mlx.html)
- [toukoum/fractol/42](https://github.com/toukoum/fractol-42)

### AI usage

AI was used throughout this project's development, primarily to:
- Explain project-related concepts and source learning materials.
- Diagnose and fix build/Makefile issues (compiler/linker flags, linking Libft and MiniLibX, an unrelated `-lbsd` link failure in MiniLibX's bundled test program).
- Debbug errors and serve as a guide to fix them.

Every change was reviewed and is understood before being kept in the project.
