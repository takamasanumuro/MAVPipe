#include <cstdlib>
#include <cstdio>
#include <array>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "fboat/mavlink.h"

int main() {
  std::array<char, MAVLINK_MAX_PACKET_LEN> rx_buffer = {0};
  fgets(rx_buffer.data(), rx_buffer.size(), stdin);
  std::ofstream log_file("log_received.hex");
  for (int i = 0; i < rx_buffer.size(); i++) {
    log_file << rx_buffer[i];
  }
  log_file.close();
  mavlink_message_t msg_packet;
  mavlink_status_t status;
  for (size_t i = 0; i < rx_buffer.size(); i++) {
    if (mavlink_parse_char(MAVLINK_COMM_0, rx_buffer[i], &msg_packet, &status)) {
      std::cout << "Received packet ID: [" << std::hex << std::uppercase << static_cast<int16_t>(msg_packet.msgid) << ']' << '\n';
      std::ofstream log_file("log_index.hex");
      log_file << msg_packet.msgid;
      log_file.close();
      switch (msg_packet.msgid) {
        case MAVLINK_MSG_ID_POT_READING: {
          mavlink_pot_reading_t pot_reading_struct;
          mavlink_msg_pot_reading_decode(&msg_packet, &pot_reading_struct);
          std::cout << "Custom MAVGENERATED Potentiometer reading: " << 
          std::dec << pot_reading_struct.pot_reading << '\n';
          break;
        }
        default: {
          std::cout << "Unknown packet received" << '\n';
          break;
        }
      }
    }
  }
  return 0;
}

/* void runpipe() {
  std::string strcmd = "";
  while (1) {
    std::cout << "Enter command: "; 
    std::getline(std::cin, strcmd);
    pipecommand(strcmd);
  }
}


void pipecommand(std::string strcmd) {
  std::array<char, 256> rx_buffer;
  FILE *pipe = popen(strcmd.c_str(), "r");
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
    return;
  }
  int counter = 0;
  while (fgets rx_buffer.data(), rx_buffer.size(), pipe) != nullptr) {
    std::cout << counter << ": " << rx_buffer.data();
    counter++;
  }
  pclose(pipe);
}
 */