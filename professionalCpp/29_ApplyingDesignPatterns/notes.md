## The Iterator Pattern

The iterator pattern provides a mechanism for separating algorithms or operations from the data on which they operate. 

The first problem with tightly coupling data and behaviors is that is precludes generic algorithms that work on a variety of objects. In order to write generic algorithms, you need some standard mechanism to access the contents of the objects. 

Conceptually, iterators provide a mechanism for an operation or algorithm to access a container of elements in a sequence. 

## The Abstract factory pattern

Another reason to use a factory is that maybe the creation of your objects requires certain information, state, resources, and so on, owned by the factory. A factory can also be used if creating your objects requires a complex series of steps to be executed in the right order, or if all created objects need to be linked to other objects in a correct manner, and so on.

## The Proxy Pattern

A proxy object serves as a stand-in for a real object. Such objects are generally used when using the real object would be time-consuming or impossible. 

Proxies are also called surrogates, handles, and wrappers. They are closely related in structure, but not purpose, to Adapters and Decorators. 

The rest below is from geeks for geeks

It is used to control and manage access to the object they are projected. 

### Types of proxies

Remote proxy:
They are responsible for representing the object located remotely. Talking to the real object might involve marshalling and unmarshalling of data and talking to the remote object. All that logic is encapsulated in these proxies and the client application need not worry about them.

#### Virtual proxy:

These proxies will provide some default and instant results if the real object is supposed to take some time to produce results. These proxies initiate the operation on real objects and provide a default result to the application. Once the real object is done, these proxies push the actual data to the client where it has provided dummy data earlier.

#### Protection proxy:

If an application does not have access to some resource then such proxies will talk to the objects in applications that have access to that resource and then get the result back.

#### Smart Proxy:

A smart proxy provides additional layer of security by interposing specific actions when the object is accessed. An example can be to check if the real object is locked before it is accessed to ensure that no other object can change it.