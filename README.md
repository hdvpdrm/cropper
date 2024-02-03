# Cropper
minimalist tool to crop png/jpg images.
<br><br><br>

Tested on ```Arch linux``` with ```gcc 13.2.1```

### Dependecies
* ```SDL2```
* ```SDL_image```<br><br>
They can easily be installed with your package manager.<br>

```bash
sudo pacman -S sdl2
sudo pacman -S sdl2_image
```

### How to build
```bash
git clone https://github.com/hdvpdrm/cropper.git
cd cropper
./build.sh
```


### Usage
```Usage example: ./cropper input_image.png output_image.png```<br>
        
### Hot keys:                                                  
W,A,S,D - to change left high edge's position<br>
Arrows  - to change right bottom edge's position<br>
Double SPACE - to crop image, save and quit<br>
X - increase movement velocity<br>
Z - decrease movement velocity<br>

### Note:<br> 
After you hit first SPACE you can press ESCAPE to continue editing.
