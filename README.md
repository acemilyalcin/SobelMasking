# Sobel Masking

Sobel filter applied on binary image and after applied some logical operations (AND, OR etc.) on the image. For make this logical operations, I used methods of operator overloading .
![Original Image](https://www.researchgate.net/profile/Dibya_Bora4/publication/314446743/figure/fig3/AS:470301768196096@1489140087642/Original-Lena-Color-Image.png)

![](https://i.ibb.co/DVwpsF7/image.png)
## Installation

```bash
g++ *.cpp src/*.cpp
```

## Usage
./a.out <image1>.bin <image2>.bin <textfile>.txt

Info: Repo is contains example binary images.
```bash
./a.out image1.bin image2.bin image.txt
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
