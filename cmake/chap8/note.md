# Using CTest to standardize testing

*SUT* = System Under Test

Running an automated testing involves nothing other than running an executable
that sets your SUT in a given state, prforms tested operations, and checks if
the results match expectations.

CMake comes with CTest for testing.

# Structuring our projects for testing

There are many ways to go about the project structure when it comes to testing.
But, the most used approach is to build our entire solution as a library and
link it with unit tests for testing.

If we want to run it as an executable, we'll need a wrapper that'll call the
library from the `main()` function of the executable and pass the envrionment
variables.
