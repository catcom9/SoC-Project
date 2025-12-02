---
layout: home
title: FPGA VGA Driver Project
tags: fpga vga verilog
categories: demo
---

This is my write up on my SOC FPGA Project. It details the steps taken to display a 640x480 image over VGA using the Basys 3 development board.


## **Template VGA Design**
### **Project Set-Up**

<img src="docs/assets/images/VGAProject.png">

### **Template Code**

For the project we received a project template. This tempate included all the files needed to display colour strips on the monitor. The template included three files.
 - VGATop.v
    - The top level verilog file. This calls all the other modules and connects the signals in between them.
 - VGASync.v
    - Creates the signals for VGA to work. A horizonal sync and verital sync signals are generated here. These signals are directly sent to the monitor. A pulse on the horisontal sync signifys the end of the line, while a pulse on the vertical sync means the end of a full frame.
 - VGAColourCycle.v
    - Generates the colour data for displaying on the screen. As the name suggests it cycles through a few colors.
 - Basys3_Master.xdc
    - Constraints file for the board. Needed to set up the switch for the reset, the outputs for the VGA connector and for the clock.
 - Testbench.v
    - Test bench used to see if the design works correctly.

### **Synthesis**
Synthesis and Im is the process of converting the verilog implementation
### **Demonstration**
Perhaps add a picture of your demo. Guideline: 1/2 sentences.

## **My VGA Design Edit**
Introduce your own design idea. Consider how complex/achievabble this might be or otherwise. Reference any research you do online (use hyperlinks).
### **Code Adaptation**
Briefly show how you changed the template code to display a different image. Demonstrate your understanding. Guideline: 1-2 short paragraphs.
### **Simulation**
Show how you simulated your own design. Are there any things to note? Demonstrate your understanding. Add a screenshot. Guideline: 1-2 short paragraphs.
### **Synthesis**
Describe the synthesis & implementation outputs for your design, are there any differences to that of the original design? Guideline 1-2 short paragraphs.
### **Demonstration**
If you get your own design working on the Basys3 board, take a picture! Guideline: 1-2 sentences.

## **More Markdown Basics**
This is a paragraph. Add an empty line to start a new paragraph.

Font can be emphasised as *Italic* or **Bold**.

Code can be highlighted by using `backticks`.

Hyperlinks look like this: [GitHub Help](https://help.github.com/).

A bullet list can be rendered as follows:
- vectors
- algorithms
- iterators

Images can be added by uploading them to the repository in a /docs/assets/images folder, and then rendering using HTML via githubusercontent.com as shown in the example below.

<img src="https://raw.githubusercontent.com/melgineer/fpga-vga-verilog/main/docs/assets/images/VGAPrjSrcs.png">
