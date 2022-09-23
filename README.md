# OpenGL configuration in Visual Studio

This tutorial aims to make easy the instalation of OpenGl and its libraries and configure them in Visual Studio. The libraries used are GLFW, GLEW, and GLM.
The zips to the libraries will be linked in this README but also placed in this repository for the convinience of the user.

Also two vscode templates will be avaiable here but in order to use them the user must change the location of the **lib** and **include** folders of the libraries in the project settings (not reccomended).

## 1º step: Download Visual Studio

Go to ![this link](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false) to download the latest version of visual studio community edition

When installing, check the c++ development kit in the addons, as it is necessary
 
## 2º step: Download the libraries

Download ![GLFW binaries](), ![GLEW binaries]() and ![GLM](), or just download the correct zips in this repository located in the folder **Binaries**.

Then, place the content of the zips in a folder well located because they're going to be used from there.

## 3º step: Configure the project (If you didn't use the templates)

Create a new c++ console app project and create a .cpp file if it doesn't exist (it's important because some options are unavailable if no file is present).

### 3.1 - Configure the includes

Go to Project properties -> C/C++ -> Additional Include Directories, and click on it.

Add the following lines: (* is the path to the folder you created to store the libraries)

- ***\glfw-3.3.8.bin.WIN64\include**
- ***\glew-2.1.0\include**
- ***\glm\glm**

### 3.2 - Configure the libs

Go to Project properties -> Linker -> General -> Additional Library Directories, and click on it.

Add the following lines: (* is the path to the folder you created to store the libraries)

- ***\glfw-3.3.8.bin.WIN64\lib-vc2022** (According to the version of the IDE)
- ***\glew-2.1.0\lib\Release\x64** (According to the arquitecture of the computer

### 3.3 - Configure the Input Linker

Go to Project properties -> Linker -> Input -> Additional Dependencies, and click on it.

Add the following:

- opengl32.lib
- glew32.lib
- glfw3.lib

## 4º step - Add code

Copy the file Main.cpp or simply its content to the created .cpp file and run the code

## 5º step (OPTIONAL) - Create template of the project so this is a one-time process

Go to Project -> Export Template and proceed with its creation
