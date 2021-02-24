![NeoDoa](https://user-images.githubusercontent.com/25724155/72576385-9ca35100-38e0-11ea-9f10-5de3852e6df3.png "NeoDoa Logo")

# NeoDoa Game Engine

NeoDoa is a simple, open-source and easy-to-use game engine developed with C++ for high fun game development! NeoDoa uses OpenGL to deliver high performance by hardware accelerating the rendering.

## Features

NeoDoa is still under development. Below are the finished and upcoming features.

* **Graphics**
    * OpenGL 4.5 Core Profile based renderer
    * Soon: Point and spot and custom lights
	* Soon: High Quality Text Rendering using [Signed Distance Fields](https://steamcdn-a.akamaihd.net/apps/valve/2007/SIGGRAPH2007_AlphaTestedMagnification.pdf)
	* Soon: Shadows
	* Soon: Waters
	* Soon: Skybox
	* Soon: Deferred Shading
	* Soon: Skeletal Animation
* **Collision & Physics**
    * Soon: With PhysX
* **Audio**
    * Soon: With OpenAL
* **Asset Loading
	* 3D models loading via [Assimp](https://www.assimp.org/)
	* Texture loading via [stb_image](https://github.com/nothings/stb)
* **Scripting system**
	* Scripting via [AngelScript](https://www.angelcode.com/angelscript/)
	* Create a script, fill in the "Execute" function, attach it to an Entity!
* **Input**
    * Mouse, Keyboard. 
	* Soon: Controller
	* Soon: Joystick

## How to build

You need Visual Studio 2019 to build NeoDoa in the most convenient and easy way possible. Older versions may work but wasn't tested against.

 * Clone the repository
 * Open Visual Studio
 * File->Open->Project/Solution
 * Select "NeoDoa.sln" in the root of repo
 * Set "Editor" as the start-up project
 * Hit F5
 
A single window named "NeoDoa Editor" will appear.

## Contributing

Want to help me make this project better? Great!
Check out [CONTRIBUTING.md](https://github.com/aeris170/NeoDoa/blob/master/CONTRIBUTING.md) to get started.

### Github Issues

Please use [Github Issues](https://github.com/aeris170/NeoDoa/issues) to report bugs or request features.

### Reporting bugs

Please follow these steps to report a bug

1. **Search for related issues** - search the existing issues so that you don't create duplicates

2. **Create a testcase** - please create the smallest isolated testcase that you can that reproduces your bug

3. **Share as much information as possible** - everything little helps, OS, IDE, GPU, all that stuff.

## NeoDoa Platform

NeoDoa is an open source game engine which you can use to develop games and it is strictly for Windows PC (at the moment).
If you want to bring multi-platform support, fell free to get your hands dirty. All help is welcome!

## License

NeoDoa is released under its own license. See [licence](https://github.com/aeris170/NeoDoa/LICENCE).