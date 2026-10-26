TinyML: Motor Vibration Classification on STM32F407

A Beginner's Design Guide from Bare-Metal Programming to Machine Learning on Embedded Hardware

This project demonstrates the complete workflow of developing a basic TinyML application, starting with simulated motor vibration data in Python and ending with Machine Learning inference on an STM32F407 Discovery board.

The goal is to help beginners understand how Python-based Machine Learning can be integrated with embedded C and microcontroller hardware.

Repository: TinyML Motor Vibration Classification

🎯 Project Objectives

Understand the connection between bare-metal embedded programming and Machine Learning.

Generate synthetic motor vibration data using Python.

Extract numerical features from vibration signals.

Train a Decision Tree classifier using Scikit-learn.

Convert the trained model into C source and header files.

Integrate the model into STM32CubeIDE.

Execute inference on the STM32F407 Discovery board.

Indicate the predicted vibration class using onboard LEDs.

🧭 Learning Path

The project follows this learning sequence:

Bare-Metal Programming — Register-level GPIO configuration and LED control.

Python and Synthetic Data — Generate simulated vibration signals and assign labels.

Feature Engineering — Calculate features such as variance and peak amplitude.

Machine Learning — Train a Decision Tree classifier using Scikit-learn.

Model Conversion — Represent the trained Decision Tree as C code.

Embedded Integration — Add the generated C files to an STM32CubeIDE project.

Hardware Inference — Execute the classification logic on the STM32F407.

GPIO Output — Display the predicted class using onboard LEDs.

🧪 Understanding Synthetic Data

Synthetic data is artificially generated data that imitates selected characteristics of real-world measurements.

In this project, Python generates simulated vibration signals representing three classes:

Normal

Imbalance-like

Excessive vibration

Using synthetic data allows the initial Machine Learning workflow to be developed without a physical motor or vibration sensor.

The generated signals are converted into numerical features that can be used to train a Decision Tree classifier.

Important: Synthetic data is useful for learning and prototyping, but it does not guarantee that a model will correctly identify faults in a real motor. Real sensor measurements are required for practical validation.

🧠 Machine Learning Model

The project uses a Decision Tree classifier trained with Python and Scikit-learn.

The generated C model uses two input features:

variance

peak

The current classification rules are:

Condition

Predicted class

Variance ≤ 0.12

NORMAL

Variance > 0.12 and peak ≤ 1.02

IMBALANCE_LIKE

Variance > 0.12 and peak > 1.02

EXCESSIVE_VIBRATION

These thresholds belong to the current generated model and are intended for the simulated-data demonstration. They are not validated motor fault thresholds.

⚙️ Embedded Hardware

Target board: STM32F407 Discovery

Development environment: STM32CubeIDE

The trained Decision Tree is represented in C and integrated into the embedded firmware.

The application calls:

VibrationClass result =
    classify_vibration(variance, peak);

The returned class is used to select an LED indication.

LED

Example classification

Green — PD12

Normal

Orange — PD13

Imbalance-like

Red — PD14

Excessive vibration

The current prototype uses fixed feature values for initial inference testing. Real-time accelerometer acquisition and feature extraction are future extensions.

🛠️ Software and Tools

Python

Jupyter Notebook

Scikit-learn

Embedded C

STM32CubeIDE

STM32F407 Discovery board

🚀 Getting Started

1. Explore the Python notebook

Open Simulated_motor_vibration.ipynb in Jupyter Notebook or JupyterLab.

Use the notebook to understand the simulated-data workflow and model development. Ensure the required Python code cells and dependencies are present before running it.

2. Inspect the generated C model

Review:

vibration_model.c

vibration_model.h

The header defines the VibrationClass enumeration and the classify_vibration() function interface.

3. Open the STM32CubeIDE project

Import the complete STM32CubeIDE project into your workspace.

Ensure the model source file is included in the build and the header is accessible through the project's include paths.

4. Build and flash

Build the firmware, connect the STM32F407 Discovery board using its ST-LINK interface, and flash the program.

5. Test the classification

Use controlled feature values to test each classification path and verify the corresponding LED output.

For example, variance = 0.01f should return NORMAL under the current model rules.

📂 Project Components

The repository includes the Python notebook and the embedded model files used for the demonstration. The STM32CubeIDE project contains the application code, GPIO functions, and required project configuration.

The exact directory structure depends on the files included in the repository.

🔧 Future Enhancements

Interface a physical accelerometer using SPI or I²C.

Acquire real motor vibration samples.

Calculate variance and peak directly on the STM32.

Evaluate model performance on unseen real measurements.

Compare simulated-data results with real sensor data.

Improve classification robustness using representative motor datasets.

📚 Who Is This Project For?

This project is intended for:

Beginners learning embedded systems and Machine Learning.

Embedded C developers interested in TinyML.

Students exploring Edge AI and microcontroller-based inference.

Engineers who want to understand the transition from Python model development to embedded C deployment.

⚠️ Project Status

This is an educational prototype using simulated vibration data and fixed feature inputs for initial embedded inference testing. It has not been validated as a real-world motor fault detection system.

👩‍💻 Author

Created as a practical design guide connecting bare-metal programming, embedded C, Python-based Machine Learning, and TinyML deployment.

If this project helps you understand the journey from microcontroller fundamentals to embedded AI, feel free to explore the repository and build on it.
