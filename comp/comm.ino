/*
 COMMUNICATION CODE

 GSEA NEAR SPACE BALLOON

 SEPTEMBER 2015.  ALL RIGHTS RESERVED.
 */

#define RADIOPIN 9

void setup() {
	pinMode(RADIOPIN, OUTPUT);
	setPWMFrequency(RADIOPIN, 1);
}

void loop() {
	// alternate between high and low frequency @ 2Hz.
	analogWrite(RADIOPIN, 100);
	delay(500);
	analogWrite(RADIOPIN, 110);
	delay(500);
}

/*
 * Set PWM frequency as fast as possible.
 */
void setPWMFrequency(int pin, int divisor) {
	byte mode;

	if (pin == 5 || pin == 6 || pin == 9 || pin == 10) {
		switch (divisor) {
			case 1:
				mode = 0x01;
				break;
			case 8:
				mode = 0x02;
				break;
			case 64:
				mode = 0x03;
				break;
			case 256:
				mode = 0x04;
				break;
			case 1024:
				mode = 0x05;
				break;
			default:
				return;
		}
		
		if (pin == 5 || pin == 6) {
			TCCR0B = TCCR0B & 0b11111000 | mode;
		} else {
			TCCR1B = TCCR1B & 0b11111000 | mode;
		}
	} else if (pin == 3 || pin == 11) {
		switch (divisor) {
			case 1:
				mode = 0x01;
				break;
			case 8:
				mode = 0x02;
				break;
			case 32:
				mode = 0x03;
				break;
			case 64:
				mode = 0x04;
				break;
			case 128:
				mode = 0x05;
				break;
			case 256:
				mode = 0x06;
				break;
			case 1024:
				mode = 0x07;
				break;
			default:
				return;
		}

		TCCR2B = TCCR2B & 0b11111000 | mode;
	}
}

byte[] hadamard(byte msg) {
	byte[] enc = new byte[7];

	for (byte ct = 0; i < 64; i++) {
		byte i = ct + 64;
		// multiply corresponding bits
		byte a = i & msg;
		// sum (mod 2)
		a ^= a >> 8;
		a ^= a >> 4;
		a ^= a >> 2;
		a ^= a >> 1;
		a &= 1;
		// store in enc array
		enc[ct / 8] += a << (7 - ct % 8);
	}

	return enc;
}
