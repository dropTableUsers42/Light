# Contributing

To ensure uniformity throughout our codebase, we have a few rules:

### Branches
1. Any new features must be in their own branch, which will branch from the `development` branch.
2. The branch should be named `feature/<feature-name>`. For example, if we are adding collision detection, then the branch where the work is being done should be called `feature/collision-detection`.
3. One feature per branch.
4. After a feature is done, a pull request must be submitted on the `development` branch for review.
5. Before merging a pull request, make sure that it passes the CI tests.

### Code Style

#### Header Files and Classes 
1. Header files go in the `include` directory, and source files go in the `src` directory.
2. Don't use `using namespace std` in header files. If it is necessary (because of very long type names), try to restrict it to the smallest scope possible.
3. In classes, prefix all member variables with the `m_` prefix. For example, if the class has a member variable for position, it should be called `m_position`.
4. Member variables and member functions should use camelCase. That is, if the variable name consists of multiple words, the first letter of the word should be lowercase and the first letter of all subsequent words should be uppercase. Examples: `m_angularVelocity`, `getAngularVelocity()`, `m_gravity`, `getGravity()`, `m_transformComponent`.
5. Class names should use PascalCase. That is, if the class name consists of multiple words, the first letter of every word should be in uppercase. Examples: `PhysicsWorld`, `RigidBody`. 
6. Getters and setters for classes should be marked as `inline`.

#### General Programming Conventions
1. Curly braces should be on new lines.
2. Source file names should be in all lowercase. They should typically be one word (things like `physicsworld.*` and `rigidbody.*` are fine). If you find that your source file name consists of multiples, that might indicative of bad design.
3. Use tabs instead of spaces. Make sure that all tabs are equal to 4 spaces.
4. Put spaces around binary operators. For example, write `a += b` and not `a+=b`. The former looks less cluttered.
5. Use blank lines to logically separate portions of code.
6. Function definitions should have at least one blank line after them (an exception being if it is the last function in a class definition).