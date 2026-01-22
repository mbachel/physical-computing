# ITIS 5358 Physical Computing Portfolio

A semester-long portfolio of **3D printing**, **laser cutting**, and **Arduino** work created for ITIS 5358.

This repository is organized as a set of dated prep-work and in-class exercises, plus larger end-to-end projects (CAD → fabrication → code → documentation).

## Table of contents

- [What this project does](#what-this-project-does)
- [Why this project is useful](#why-this-project-is-useful)
- [Repository tour](#repository-tour)
- [Highlights (good starting points)](#highlights-good-starting-points)
  - [Arduino sketches](#arduino-sketches)
  - [Videos / demos](#videos--demos)
- [How to use this repository](#how-to-use-this-repository)
  - [Browse by category](#browse-by-category)
  - [Open and run Arduino sketches](#open-and-run-arduino-sketches)
  - [View fabrication files](#view-fabrication-files)
- [Notes on sources and attribution](#notes-on-sources-and-attribution)
- [Who maintains and contributes](#who-maintains-and-contributes)
- [License](#license)

## What this project does

- Collects and showcases hands-on deliverables from a Physical Computing course:
  - 3D models and prints (e.g., `.stl`, `.f3d`, `.gcode`)
  - Laser cutting designs (e.g., `.svg`, `.dxf`, exported PDFs)
  - Arduino sketches (e.g., `.ino`) and supporting media (photos/videos/screenshots)
- Preserves the “trail” of iteration over the semester: early practice, in-class activities, and finished projects.

## Why this project is useful

- **Portfolio-friendly**: everything is in one place with artifacts (models, code, photos, videos) tied to each activity.
- **Reusable references**: quick examples for common physical computing patterns:
  - Digital outputs and PWM
  - Buttons and basic digital inputs
  - Sensors (photoresistors, temperature)
  - Motors (DC motors, H-bridge control, servos)
  - LCD usage (including custom characters/progress bars)
  - Arduino UNO R4 WiFi LED matrix demos
  - WiFi + NTP time sync + RTC usage (in the semester project)
- **Easy to browse**: folders are grouped into prep, in-class, and project work.

## Repository tour

- [Projects/](Projects/) — the larger, graded projects (usually with documentation + media + final files)
  - [Projects/Project 7 Graduate Project/](Projects/Project%207%20Graduate%20Project/) — capstone-style independent project
  - [Projects/Project 6 Undergraduate Project/](Projects/Project%206%20Undergraduate%20Project/) — integrated semester project (CAD + code + outputs)
  - [Projects/Project 5 Builing a Roving Robot/](Projects/Project%205%20Builing%20a%20Roving%20Robot/) — robotics build with videos + sketches
  - [Projects/Project 4 Basic Laser Cutting/](Projects/Project%204%20Basic%20Laser%20Cutting/) — laser cutting designs and exported PDFs
  - [Projects/Project 3 3D Print Your Autodesk Fusion Practical Print Design/](Projects/Project%203%203D%20Print%20Your%20Autodesk%20Fusion%20Practical%20Print%20Design/) — Fusion-based CAD → printable design
  - [Projects/Project 2 3D Printed Balloon Car/](Projects/Project%202%203D%20Printed%20Balloon%20Car/) — iterative balloon car design + prints
  - [Projects/Project 1 Initial Print/](Projects/Project%201%20Initial%20Print/) — first print and baseline setup
- [In-Class Activities/](In-Class%20Activities/) — guided class activities (Arduino + CAD)
- [Prep Work/](Prep%20Work/) — pre-class prep exercises and practice
- [assignment template/](assignment%20template/) — base structure used for assignments
- [Unsorted/](Unsorted/) — misc files not yet categorized

> Note: Several Arduino sketches live inside folders named `STL Files/` due to the template folder structure.

## Highlights (good starting points)

### Arduino sketches

- Light-following / roving robot (H-bridge + photoresistors):
  - [Projects/Project 5 Builing a Roving Robot/STL Files/roving-robot.ino](Projects/Project%205%20Builing%20a%20Roving%20Robot/STL%20Files/roving-robot.ino)
- UNO R4 WiFi LED matrix scrolling text example:
  - [Prep Work/10-13 Prep Using the Arduino UNO R4 WiFi LED Matrix/STL Files/scrollingtext.ino](Prep%20Work/10-13%20Prep%20Using%20the%20Arduino%20UNO%20R4%20WiFi%20LED%20Matrix/STL%20Files/scrollingtext.ino)
- LCD progress bar demo:
  - [In-Class Activities/11-10 Class Arduino - LCD Display/STL Files/lcd.ino](In-Class%20Activities/11-10%20Class%20Arduino%20-%20LCD%20Display/STL%20Files/lcd.ino)
- Integrated semester project sketch (WiFi + NTP + RTC + LCD + LED matrix + I2C expanders):
  - [Projects/Project 6 Undergraduate Project/Special Files/physical_code/physical_code.ino](Projects/Project%206%20Undergraduate%20Project/Special%20Files/physical_code/physical_code.ino)

### Videos / demos

Please request demos from me if interested.

## How to use this repository

### Browse by category

- Want *finished, polished deliverables*? Start in [Projects/](Projects/).
- Want *week-by-week exercises and skill-building*? Browse [Prep Work/](Prep%20Work/) and [In-Class Activities/](In-Class%20Activities/).

### Open and run Arduino sketches

1. Install the Arduino IDE (or Arduino CLI).
2. Open any `.ino` file from this repo.
3. Select the correct board (many sketches target **Arduino UNO R4 WiFi**).
4. Install any required libraries if prompted.

Example (UNO R4 WiFi LED matrix):
- Open [Prep Work/10-13 Prep Using the Arduino UNO R4 WiFi LED Matrix/STL Files/scrollingtext.ino](Prep%20Work/10-13%20Prep%20Using%20the%20Arduino%20UNO%20R4%20WiFi%20LED%20Matrix/STL%20Files/scrollingtext.ino)
- Ensure the `ArduinoGraphics` and `Arduino_LED_Matrix` libraries are available.

### View fabrication files

- **3D printing**: open `.stl` in a slicer (e.g., PrusaSlicer/Cura/OrcaSlicer). Some projects also include `.gcode` outputs.
- **CAD**: open `.f3d` in Autodesk Fusion.
- **Laser cutting**: open `.svg` / `.dxf` in a tool like Inkscape, Fusion, or the laser cutter’s software.

## Notes on sources and attribution

Some sketches include headers referencing external tutorials/books (for example, *Exploring Arduino, Second Edition*). Those files retain their original attribution and licensing notes.

One common source used for learning/reference material:
- https://github.com/sciguy14/Exploring-Arduino-2nd-Edition

## Who maintains and contributes

- **Maintainer**: Matthew Bachelder (GitHub: https://github.com/mbachel, email: matthew@bachelder.me)
- **Contributions**: This repo is primarily a course portfolio. Issues are welcome for questions or clarifications.

## License

This repository is licensed under the MIT License. See [LICENSE](LICENSE).
