# Garod - Automated Gardening Tool

Garod is an automated gardening tool that monitors various parameters of plants' environment, including light intensity, soil moisture, temperature, and humidity. The data is collected by an Arduino Uno board equipped with an ESP-01 Wi-Fi module, LDR module, soil moisture module, and DHT module. The data is then sent to a Golang server script via a POST request, which can be accessed by clients to view the current status of the plants.
## Getting Started
### Prerequisites

- Arduino Uno board
- ESP-01 Wi-Fi module
- LDR module
- Soil moisture module
- DHT module
- Golang (for the server-side script)

### Installing

1. Clone the repository: `git clone https://github.com/Dagread/Garod.git`
2. Connect the components according to the circuit diagram below(GarodScheme.png)
3. In `char[] server_ip = "<your_ip>"` and `char[] server_port = "<your_port>"` replace `<your_ip>` and `<your_port>` with IP-adress and port of server that runs `Garod_Server.go`
4. Connect your ESP-01 Wi-Fi module to you Wi-Fi network
5. Upload the `Garod_Client.ino` sketch to the Arduino Uno board
6. Run the `Garod_Server.go` script on the server using Golang: `go run Garod_Server.go`

#### Circuit Diagram
![circuit diagram](https://github.com/Dagread/Garod/blob/main/Scheme/GarodScheme.png?raw=true)

### Usage

1. No usage yet, will add when implemented

## Contributing

Contributions are welcome! Please submit a pull request if you have any bug fixes, new features, or improvements.
### License

This project is licensed under the MIT License - see the LICENSE.md file for details.
## Acknowledgments

- Thanks to the creators of the Arduino and Golang programming languages for making this project possible.
