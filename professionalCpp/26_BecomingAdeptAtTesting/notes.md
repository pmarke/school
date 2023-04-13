## Becoming Adept at Testing

Two testing types
* white-box testing
* black-box testing

### Unit Testing

Idealy, one or more unit tests should exist for every low-level task that your code can perform. 
Well-written unit tests protect you in many ways:
1. They prove thtat a piece of functionality actually works.
2. They provide a first alert when a recently introduced change breaks something. This specific usage called a regression test, is covered later in this chapter.
3. When used as part of the development process, they force the developer to fix problems from the start. 
4. Unit tests let you try out code before other code is in place.
5. They provide an example of usage

#### Approaches to Unit Testing

The Extreme Programming methodology instructs its followers to write unit tests before writing code. Writing tests first helps you solidify the requirements for the components. 

Keeping unit-testability in mind during the design phase can influence the design decisions you make for your software. As you code, thing how you will test the functionality. Consider what kinds of tests you will have. 

To reach deadlines, developers tend to skip writing unit tests, because they think they will finish faster that way. Unfortunately, this thinking does not take the whole picture into account. Omitting tests will back-fire in the long run. 

Until unit test creating becomes second nature, approach the task of figuring out which tests to write by brainstorming. To get some ideas flowing, consider the following questions:
1. What are the things that this piece of code was written to do?
2. What are the typical ways each method would be called?
3. What preconditions of the methods could be violated by the caller?
4. How could each method be misused?
5. What kinds of data are you expecting as input?
6. What kinds of data are you not expecting as input?
7. What are the edge cases or exceptional conditions?


#### Write the Tests
* Make sure that you're testing only one thing in each test (or at least one new thing).
* Be specific inside the test.
* Use logging extensively inside of test code. If the test fails someday, you will have some insight into what happened. 
* Avoid tests that depend on earlier tests or are otherwise interrelated. Tests should be as atomic and isolated as possible. 
* If the test requires the use of other subsystems, consider writing stubs or mocks of those subsystems that simulate the modules' behavior so that changes in loosely related code don't causee the test to fail. (gmock and interfaces).
* Ask your code reviewers to look at your unit tests as well. 

Show examples of gtest and gmock. 


### Integration Testing

An integration test covers areas where components meet. Unlike a unit test, which generally acts on the level of a single class, an integration test usually involves two or more classes.
* Excel at testing interactions between two components.
* Can reveal incompatibilities in designs. 
* Can test a wrapper around a 3rd party library.

### System Tests

These tests examine the program as a whole. 
* They can make use of virtual users that simulates a human being working the program
* Much like unit and integration tests, and individual system test performs a speciic test and expects a specific result. 
* Used to tests that different features work in combination with one another.

### Regression Tests
A testing concept that is put in place to ensure that certain features continue to function properly as code is added or modified. They provide a sanity check that nothing is broken. 