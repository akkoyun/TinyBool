# TinyBool Library V1.0

![GitHub release (latest by date)](https://img.shields.io/github/v/release/akkoyun/TinyBool) ![Visits Badge](https://badges.pufler.dev/visits/akkoyun/TinyBool) ![GitHub stars](https://img.shields.io/github/stars/akkoyun/TinyBool?style=flat&logo=github) ![Updated Badge](https://badges.pufler.dev/updated/akkoyun/TinyBool) ![PlatformIO Registry](https://badges.registry.platformio.org/packages/akkoyun/library/TinyBool.svg)

---

TinyBool is a lightweight and efficient library designed for handling bit-level operations in embedded systems, particularly suitable for platforms like Arduino. It provides a flexible way to manage and manipulate bits stored in a dynamically allocated memory block.

## Features

- Dynamic memory allocation based on the required number of bits.
- Bit manipulation methods to set, clear, and read individual bits.
- Use of templates to handle different data sizes efficiently.
- Safe handling of memory with automatic deallocation.

## Installation

To install the TinyBool library, follow these steps:

1. Download the latest release from the GitHub repository.
2. Extract the downloaded archive to your Arduino/libraries folder.
3. Restart the Arduino IDE to load the new library.

## Usage

Here is a basic example of how to use the TinyBool library:

```cpp
#include "TinyBool.h"

TinyBool myBits(16); // Initialize TinyBool with space for 16 bits

void setup() {
  Serial.begin(115200);

  // Set and clear bits
  myBits[_Bit_03_] = true; // Set the 4th bit
  myBits[_Bit_03_] = false; // Clear the 4th bit
  myBits[_Bit_03_] = !myBits[_Bit_03_]; // Toggle the 4th bit

  // Read a bit
  bool bitStatus = myBits[_Bit_03_];
  Serial.println(bitStatus); // Outputs: 0
}

void loop() {
  // Loop code here
}
```

## API Reference

- TinyBool(uint8_t size) - Constructor to initialize the bit array.
- ~TinyBool() - Destructor to free allocated memory.
- operator[] (uint8_t pos) - Access or modify a specific bit.

## Contributing

Contributions to the TinyBool library are welcome. Please feel free to fork the repository, make your changes, and submit a pull request.

## License

TinyBool is released under the MIT License. See the LICENSE file for more details.

### Explanation

- **Features**: Briefly describes what the library does and its key features.
- **Installation**: Provides steps on how to install the library.
- **Usage**: Offers a simple example demonstrating the basic functionality.
- **API Reference**: Lists and describes the main functions and operators provided by the library.
- **Contributing**: Encourages users to contribute to the project.
- **License**: Notes the type of license under which the library is released.

---

[![Support me](https://img.shields.io/badge/Support-PATREON-GREEN.svg)](https://www.patreon.com/bePatron?u=62967889) ![Twitter Follow](https://img.shields.io/twitter/follow/gunceakkoyun?style=social) ![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UCIguQGdaBT1GnnVMz5qAZ2Q?style=social) ![Repos Badge](https://badges.pufler.dev/repos/akkoyun) [![E-Mail](https://img.shields.io/badge/E_Mail-Mehmet_Gunce_Akkoyun-blue.svg)](mailto:akkoyun@me.com)
