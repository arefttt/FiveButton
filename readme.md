first ai created arduino library
## README.md

```markdown
# FiveButton

FiveButton is an Arduino library for handling button inputs with support for single, double, and triple clicks, as well as hold and long hold events. It also supports both regular input and input pull-up modes. This library was written by AI developed by Microsoft Bing, with contributions from Mohammad Aref Tamanadar.

## Features

- Single, double, and triple click detection
- Hold and long hold detection
- Support for both regular input and input pull-up modes

## Installation

1. Download the latest release of this library from the releases page.
2. In the Arduino IDE, go to Sketch > Include Library > Add .ZIP Library... and select the downloaded file.

## Usage

Include the library at the top of your sketch:

```cpp
#include "FiveButton.h"
```

Create a new `FiveButton` object:

```cpp
#define BUTTON_PIN A0
FiveButton myButton(BUTTON_PIN, true); // true for input pull-up mode, false for regular input mode
```

In your `loop` function, call the `checkButton` method to check for button events:

```cpp
int event = myButton.checkButton();

switch (event) {
  case 1:
    Serial.println("Single click");
    break;
  case 2:
    Serial.println("Double click");
    break;
  case 3:
    Serial.println("Triple click");
    break;
  case 4:
    Serial.println("Hold");
    break;
  case 5:
    Serial.println("Long hold");
    break;
}
```

## Contributing

Contributions are welcome! Please read our contributing guidelines before getting started.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
```

## Wiki

### Home

Welcome to the FiveButton wiki! This library allows you to handle button inputs on your Arduino projects with ease. It supports single, double, and triple clicks, as well as hold and long hold events. It also supports both regular input and input pull-up modes. This library was written by AI developed by Microsoft Bing, with contributions from Mohammad Aref Tamanadar.

### Getting Started

To get started with FiveButton, you'll need to install the library in your Arduino IDE. You can download the latest release from the releases page on this repository. Once downloaded, you can add it to your Arduino IDE by going to Sketch > Include Library > Add .ZIP Library... and selecting the downloaded file.

### Examples

You can find examples of how to use this library in the `examples` directory of this repository. These examples will show you how to use all of the features of this library.

### API Reference

The API reference contains detailed information about the classes and functions provided by this library. You can find it [here](https://github.com/yourusername/FiveButton/wiki/API-Reference).

### Troubleshooting

If you're having trouble using this library, please check out our troubleshooting guide. If you're still having issues, feel free to open an issue on this repository.

### Contributing

We welcome contributions to this project! Please read our contributing guidelines before getting started.
