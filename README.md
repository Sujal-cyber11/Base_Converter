# Base Converter

A command-line program written in C that converts whole and fractional numbers
between any two bases from 2 to 36.

## Features

- Converts numbers between bases 2 through 36.
- Handles whole numbers and fractional numbers.
- Uses `.` as the fractional separator.
- Prints the converted value directly in the terminal.

## Build

```bash
gcc Base_Converter.c -o base_converter
```

## Run

```bash
./base_converter
```

On Windows, run `base_converter.exe`.

The program asks for the source base, result base and number in that order.

## Examples

These examples were compiled and run against the current source.

### Binary to decimal

```text
Enter Source Base :2
Enter Result Base :10
Enter The Number :1010.1

Answer-----10.5
```

### Decimal to binary

```text
Enter Source Base :10
Enter Result Base :2
Enter The Number :10.5
Answer-----1010.1000000000
```

### Decimal to hexadecimal

```text
Enter Source Base :10
Enter Result Base :16
Enter The Number :255
Answer-----FF.0000000000
```

## How it works

The converter uses two internal paths:

- **OTD (other base to decimal):** reads each digit positionally and sums
  `digit × sourceBase^position`. Fractional digits use negative powers.
- **DTO (decimal to other base):** converts the whole part by repeated division
  by the result base and converts the fractional part by repeated
  multiplication, collecting remainders and digits along the way.

The conversion result passes through a decimal `double` between the two paths.

## Limitations

- Result fractions are always printed with 10 digits.
- Only uppercase letters are recognised for digit values 10 through 35.
- There is no input validation. Invalid bases, digits or characters are not
  rejected safely.
- Negative numbers are not supported.
- Fractional input is limited to 20 digits; longer input is not handled safely.
- Whole-number handling is limited by `int`, `long long` and `double` ranges and
  precision at intermediate steps.
- The program is interactive and has no command-line flags.

## Future ideas

- Validate bases, digits and input length before conversion.
- Accept lowercase digits and make letter case consistent.
- Add configurable output precision.
- Support negative numbers.
- Replace floating-point intermediate values with exact rational or
  arbitrary-precision arithmetic.
- Add non-interactive flags and automated tests.
