/* *******************************************************************************
 *  Copyright (C) 2014-2024 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: TinyBool
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *
 *********************************************************************************/

#ifndef __TinyBool__
#define __TinyBool__

// Define Arduino Library
#ifndef __Arduino__
	#include <Arduino.h>
#endif

// Define Library Structures
#include <Defination.h>
#include <Config.h>

// Define Library Classes
class TinyBool {

	// Private context
	private:

		// Size Variable (User Bit Count)
		uint8_t Size;

		// Container Variable
		void * Container;

		// Memory Allocation
		void Allocate_Memory(void) {

			// Allocate Memory
			if (this->Size >= 1 && this->Size <= 8) {
				
				// Change Container Type
				this->Container = malloc(sizeof(uint8_t));

			} else if (this->Size >= 9 && this->Size <= 16) {

				// Change Container Type
				this->Container = malloc(sizeof(uint16_t));

			} else if (this->Size >= 17 && this->Size <= 32) {

				// Change Container Type
				this->Container = malloc(sizeof(uint32_t));

			} else if (this->Size >= 33 && this->Size <= 64) {

				// Change Container Type
				this->Container = malloc(sizeof(uint64_t));

			} else {

				// Change Container Type
				this->Container = malloc(sizeof(uint8_t));

			};

			// Handle Memory Allocation Error
			if (!this->Container) return;

			// Clear Memory
			memset(this->Container, 0, (this->Size + 7) / 8);

		};

        // Bit Reference Class (inner class)
        class BitRef {

			// Virtual Container
			void *Virtual_Container;
            
			// Bit Position
			uint8_t Bit_Position;

			// Data Size
			uint8_t Data_Size;

			// Constructor
			BitRef(void* data, uint8_t bitPos, uint8_t dataSize) : Virtual_Container(data), Bit_Position(bitPos), Data_Size(dataSize) {}

			// Public context
        	public:

				// Assignment operator to set the bit value
				BitRef& operator=(bool Value) {

					// Set Bit
					if (Value) {

						// Control for Data Size (uint8_t)
						if (Data_Size == sizeof(uint8_t)) {

							// Set Bit High
							*(uint8_t*)Virtual_Container |= (1 << Bit_Position);

						// Control for Data Size (uint16_t)
						} else if (Data_Size == sizeof(uint16_t)) {

							// Set Bit High
							*(uint16_t*)Virtual_Container |= (1 << Bit_Position);

						// Control for Data Size (uint32_t)
						} else if (Data_Size == sizeof(uint32_t)) {

							// Set Bit High
							*(uint32_t*)Virtual_Container |= (1 << Bit_Position);

						// Control for Data Size (uint64_t)
						} else if (Data_Size == sizeof(uint64_t)) {

							// Set Bit High
							*(uint64_t*)Virtual_Container |= (1 << Bit_Position);

						}

					// Reset Bit
					} else {

						// Control for Data Size (uint8_t)
						if (Data_Size == sizeof(uint8_t)) {

							// Set Bit Low
							*(uint8_t*)Virtual_Container &= ~(1 << Bit_Position);

						// Control for Data Size (uint16_t)
						} else if (Data_Size == sizeof(uint16_t)) {

							// Set Bit Low
							*(uint16_t*)Virtual_Container &= ~(1 << Bit_Position);

						// Control for Data Size (uint32_t)
						} else if (Data_Size == sizeof(uint32_t)) {

							// Set Bit Low
							*(uint32_t*)Virtual_Container &= ~(1 << Bit_Position);

						// Control for Data Size (uint64_t)
						} else if (Data_Size == sizeof(uint64_t)) {

							// Set Bit Low
							*(uint64_t*)Virtual_Container &= ~(1 << Bit_Position);

						}

					}

					// Return This
					return *this;

				}

				// Conversion operator to read the bit value
				operator bool() const {

					// Control for Data Size (uint8_t)
					if (Data_Size == sizeof(uint8_t)) {

						// Return Bit Value
						return (*(uint8_t*)Virtual_Container & (1 << Bit_Position)) != 0;

					// Control for Data Size (uint16_t)
					} else if (Data_Size == sizeof(uint16_t)) {

						// Return Bit Value
						return (*(uint16_t*)Virtual_Container & (1 << Bit_Position)) != 0;

					// Control for Data Size (uint32_t)
					} else if (Data_Size == sizeof(uint32_t)) {

						// Return Bit Value
						return (*(uint32_t*)Virtual_Container & (1 << Bit_Position)) != 0;

					// Control for Data Size (uint64_t)
					} else if (Data_Size == sizeof(uint64_t)) {

						// Return Bit Value
						return (*(uint64_t*)Virtual_Container & (1 << Bit_Position)) != 0;

					}

					// Return False
					return false;

				}

				// Friend Class
				friend class TinyBool;

        };

	// Public context
	public:

		// Constructor
		explicit TinyBool(uint8_t Size) : Size(Size), Container(nullptr) {

			// Allocate Memory
			this->Allocate_Memory();

		};

		// Destructor
		~TinyBool(void) {

			// Free Memory
			free(this->Container);

		};

		// Delete copy constructor and copy assignment operator
    	TinyBool(const TinyBool&) = delete;
    	TinyBool& operator=(const TinyBool&) = delete;		

		// Move constructor and move assignment operator
		TinyBool(TinyBool&& other) noexcept : Size(other.Size), Container(other.Container) { 
		
			// Reset Other
			other.Container = nullptr;
		
		}
		TinyBool& operator=(TinyBool&& other) noexcept {
        
			// Check for Self Assignment
			if (this != &other) {
            	
				// Free Memory
				free(this->Container);
            	
				// Copy Data
				this->Container = other.Container;
            	
				// Reset Other
				this->Size = other.Size;
            	
				// Reset Other
				other.Container = nullptr;
            
				// Reset Other
				other.Size = 0;

        	}

			// Return This
			return *this;

    	}

		static BitRef ErrorRef;

		// Operator[] to access individual bits
		BitRef operator[](uint8_t _Bit_Position) {

			// Control for Bit Position
			if (_Bit_Position >= this->Size) return ErrorRef;

			// Define Variables
			uint8_t _Byte_Offset = _Bit_Position / 8;
			uint8_t _Bit_Offset = _Bit_Position % 8;
			uint8_t _Data_Size;

			// Control for Data Size (uint8_t)
    		if (this->Size >= 1 && this->Size <= 8) {
				
				// Set Data Size
				_Data_Size = sizeof(uint8_t);

			// Control for Data Size (uint16_t)
			} else if (this->Size >= 9 && this->Size <= 16) {

				// Set Data Size
				_Data_Size = sizeof(uint16_t);

			// Control for Data Size (uint32_t)
			} else if (this->Size >= 17 && this->Size <= 32) {

				// Set Data Size
				_Data_Size = sizeof(uint32_t);

			// Control for Data Size (uint64_t)
			} else if (this->Size >= 33 && this->Size <= 64) {

				// Set Data Size
				_Data_Size = sizeof(uint64_t);

			// Default Case
			} else {

				// Set Data Size
				_Data_Size = sizeof(uint8_t);

			}

			// Return Bit Reference
			return BitRef((uint8_t*)this->Container + _Byte_Offset, _Bit_Offset, _Data_Size);

		}

		// Get Container
		void* DataContainer() const {
        	return Container;
    	}

};

// Dışarıda tanımlanmış ErrorRef nesnesi
TinyBool::BitRef TinyBool::ErrorRef(nullptr, 0, 0);

#endif /* defined(__TinyBool__) */
