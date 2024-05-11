# Quadratic Equation Solver

This C library provides functions to solve quadratic equations.

## Installation

Clone the repository and compile the code using `make`.

## Usage

Include the `quadratic_equation.h` header file in your project.

### Functions

#### `double discriminant(double a, double b, double c)`

Returns the discriminant of a quadratic equation.

- `a`: First coefficient
- `b`: Second coefficient
- `c`: Free term

Returns:
- `< 0`: No roots
- `= 0`: One root
- `> 0`: Two roots

#### `int solve_equation(double a, double b, double c)`

Returns the number of roots in a quadratic equation.

- `a`: First coefficient
- `b`: Second coefficient
- `c`: Free term

Returns:
- `0`: No roots
- `1`: One root
- `2`: Two roots

#### `Discriment* createStruct()`

Creates a structure to hold roots and the number of roots.

#### `Discriment* inputCoefficients(double a, double b, double c)`

Creates a `Discriment` structure and solves the quadratic equation using the input coefficients.

## Testing

Run the tests using `make test`.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.