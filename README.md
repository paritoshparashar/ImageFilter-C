# ImageFilter-C

## Introduction
The name of this project is inspired by the open source project `convert`, a command line tool for image manipulation. As the original `convert` project contains very extensive work, the version you have to implement only covers a fraction of `convert`’s features. The selected tasks are 
1) reading and writing images,
2) simple image manipulation e.g. rotating an image and
3) performing a flood fill operation you may know as the paint bucket tool in image editing software like Photoshop, GIMP or Microsoft Paint. <br>

Please refer to the respective sections for detailed descriptions. In the following, we will describe the technical setup.

## Initial Setup

- To obtain the project use `git clone`
- You can edit the files in the `src` folder using any text editor. We recommend using Visual Studio Code.
- To compile the project use `make` in the root project of the repository.
- After that you can use the following command to run your program: `./bin/convert command [options] > output.ppm < input.ppm`
  - Substitute command by the name and arguments for desired functionality. (Described in each section.)
  - Substitute `input.ppm` by the file path you choose as input.
  - Substitute `output.ppm` by the file path you choose as output.
  - You can find sample input files in `test/data`.
  - Use `./convert_opt` instead of `./convert` for the compiler-optimized version.<br>
  
- Please note that you should not substitute `<, >`. By default the executable reads from and writes to the command line. By using `> output.ppm` the output is redirected to `output.ppm`. By using `< input.ppm` the input is redirected to `input.ppm`.
- Use the command `./tests/run_tests.py` to run the local tests for your project. Make sure to first build your project using `make`. `make check` will build the project and run all local tests.
- You can use the `-f` flag to run a specific test. For example, `./tests/run_tests.py -f "public.read_and_write.basi0g01"` to run the test public.read_and_write.basi0g01.

## Graphical User Interface

Testing your implementation locally via the command line requires you to implement the read and write functions from section 1. If you have not yet implemented the read and write file functionality and want to test your image manipulation functions, you can use the provided Graphical User Interface (GUI). To start the GUI, you can use
the command: 
`./bin/convert gui` <br><br>
In the GUI, you will find a button on the lefthand side for each functionality that you need to implement. Click on the corresponding button to test your implementation with the pre-loaded sample image. The GUI allows you to visually inspect the results of your implementation, which can be helpful for debugging. Please note that the GUI will be closed, and an error will be printed to the command line, if you try to use functionality that you have not
implemented yet.
