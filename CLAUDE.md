# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a **Sphinx documentation repository** for the Keyestudio KS5009 IoT Smart Home Kit for ESP32. It provides assembly instructions and programming tutorials (both Arduino/C++ and MicroPython) for building an ESP32-based smart home system. The actual code examples are distributed as archived `.7z` packages inside `docs/Arduino/` and `docs/Python/`, not as version-controlled source files.

Documentation is hosted via [Read the Docs](https://readthedocs.org/) and built automatically on push.

## Build Commands

Install dependencies:
```bash
pip install -r requirements.txt
```

Build HTML locally:
```bash
sphinx-build -M html . _build
```

Built output lands in `_build/html/index.html`.

## Architecture

```
/
├── conf.py              # Sphinx configuration (theme, extensions, project metadata)
├── index.rst            # Root TOC — points into docs/
├── requirements.txt     # Sphinx + theme dependencies
├── .readthedocs.yaml    # ReadTheDocs CI: Ubuntu 24.04, Python 3.13, builds HTML + PDF
└── docs/
    ├── index.rst        # Main page: kit description, component list, assembly guide
    ├── Arduino/
    │   ├── arduino.rst                  # Arduino IDE setup + C++ tutorial pages
    │   └── Resource-compression-package.7z  # Archived Arduino sketches + drivers
    ├── Python/
    │   ├── Python.rst                   # Thonny IDE setup + MicroPython tutorial pages
    │   └── Resource-compression-package.7z  # Archived MicroPython scripts
    └── media/                           # Images embedded in .rst files
```

`docs/index.rst` is the primary content file — it contains the full assembly walkthrough, wiring tables, and links into the Arduino/Python sub-tutorials.

## Documentation Conventions

- All content is written in **reStructuredText** (`.rst`).
- Images are stored in `docs/media/` and referenced with `.. image::` directives.
- The Sphinx theme is `sphinx_rtd_theme` (Read the Docs theme), configured in `conf.py`.
- Hardware code examples appear inline in `.rst` files as `.. code-block:: c` or `.. code-block:: python` blocks; complete, runnable code lives in the `.7z` archives.

## Hardware Reference

Target board: **ESP32-WROOM-32** with Arduino IDE or Thonny (MicroPython).

Key GPIO assignments used throughout the tutorials:

| Component | GPIO |
|---|---|
| Temperature/Humidity (DHT11) | 17 |
| Yellow LED | 12 |
| Steam sensor | 34 |
| Fan (PWM) | 18, 19 |
| PIR motion sensor | 14 |
| Buttons | 16, 27 |
| 6812 RGB LED | 26 |
| Gas sensor | 23 |
| Buzzer | 25 |
| Servo (window) | 5 |
| Servo (door) | 13 |
| RFID / LCD1602 | I2C bus |
