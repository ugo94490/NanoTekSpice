# Nanotekspice
2nd year Epitech c++ project.

Done with [Florian Vincent](https://github.com/kyx42)

# Synopsis

NanoTekSpice is a logic simulator that is able to build a graph thanks to a configuration file, as well as inject values inside the graph to get results.

# Configuration file

```
# Example

.chipsets:                                                                                                                                                                                                                                     
input           a                                                                                                                                                                                                                              
input           b                                                                                                                                                                                                                              
output          s                                                                                                                                                                                                                              
4071            gate                                                                                                                                                                                                                           
                                                                                                                                                                                                                                               
.links:                                                                                                                                                                                                                                        
a:1             gate:1                                                                                                                                                                                                                         
b:1             gate:2                                                                                                                                                                                                                         
s:1             gate:3 
```

* ***Hash mark***:	allows you to commnet your configuration file.

* ***.chipshet***:	allows you to declare components tha will be used by the program and name them.

* ***.links***:     allows you to declare links between components. (You have to precise which component you wish to link and which pin).

***

* ***input***: Creates a value directly linked to the command line. The value must be 1 or 0 and must be given this way :
./nanotekspice configuration_file.ts input_name=input_value.

* ***true***: This is an input with one pin that is always true (1)

* ***false***: This is an input with one pin that is always false (0)

* ***output***: Creates an output that writes its state on *[stdout](http://en.cppreference.com/w/cpp/io/cout)* at the end of each simulation.

# Execution

After being launch, the simulator will display the result and start a command-line interpreter, which reads few commands on *[stdin](http://en.cppreference.com/w/cpp/io/cin)*

* ***exit***: It closes the program.

* ***display***: It prints the value of all outputs.

* ***input=value***: It changes the input's value (Not able with the clocks)

* ***loop***: It executes a loop with simulate until SIGINT (CTRL+C)
