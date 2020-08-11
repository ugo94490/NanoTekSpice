<!--[![Stargazers][stars-shield]][stars-url]-->
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/ugo94490/NanoTekSpice/">
    <img src="nts.jpg" alt="Logo" width="640" height="640">
  </a>

  <h3 align="center">NanoTekSpice</h3>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
* [Usage](#usage)
* [Contributor](#contributor)
* [License](#license)
* [Contact](#contact)



<!-- ABOUT THE PROJECT -->
## About The Project

NanoTekSpice is a logic simulator that is able to build a graph thanks to a configuration file, as well as inject values inside the graph to get results.

### Built With

There is no specific lib in this project.


<!-- GETTING STARTED -->
## Getting Started

```
$> make
$> ./nanotekspice configuration_file.ts input_name=input_value
```

Example: ./arcade adder.nts a=1 b=0


<!-- USAGE EXAMPLES -->
## Usage

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

After being launch, the simulator will display the result and start a command-line interpreter, which reads few commands on *[stdin](http://en.cppreference.com/w/cpp/io/cin)*

* ***exit***: It closes the program.

* ***display***: It prints the value of all outputs.

* ***input=value***: It changes the input's value (Not able with the clocks)

* ***loop***: It executes a loop with simulate until SIGINT (CTRL+C)


<!-- CONTRIBUTING -->
## Contributor

* [Ugo Levi--Cescutti](https://github.com/ugo94490)
* [Lucas Renard](https://github.com/LightFox7/)


<!-- LICENSE -->
## License



<!-- CONTACT -->
## Contact

Ugo Levi--Cescutti - [Linkedin](https://www.linkedin.com/in/ugo-levi-cescutti/) - ugo.levi-cescutti@epitech.eu

Project Link: [https://github.com/ugo94490/NanoTekSpice/](https://github.com/ugo94490/NanoTekSpice/)

[stars-shield]: https://img.shields.io/github/stars/ugo94490/NanoTekSpice.svg?style=flat-square
[stars-url]: https://github.com/ugo94490/NanoTekSpice/stargazers
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/ugo-levi-cescutti/
