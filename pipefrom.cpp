#include <cstdlib>
#include <cstdio>
#include <array>
#include <iostream>
#include <stdexcept>
#include "fboat/mavlink.h"
#include <stdint.h>
#include <fstream>

int main() {
  FILE* pipe = popen("to", "w");
  if (!pipe) {
    throw std::runtime_error("Failed to open pipe");
    return 1;
  }
  mavlink_message_t msg_packet;
  uint16_t pot_read = 530;
  mavlink_msg_pot_reading_pack(1, 200, &msg_packet, pot_read);
  std::array<uint8_t, MAVLINK_MAX_PACKET_LEN> mav_write_buffer;
  uint16_t written_len = mavlink_msg_to_send_buffer(mav_write_buffer.data(), &msg_packet);
  for (int i = 0; i < written_len; i++) {
    std::cout << "DATA[" << i << "]:" << std::hex << std::uppercase << static_cast<int16_t>(mav_write_buffer[i]) << '\n';
  }
  std::ofstream log_file("log_send.hex");
  for (int i = 0; i < written_len; i++) {
    log_file << mav_write_buffer[i];
  }
  log_file.close();
  fwrite(mav_write_buffer.data(), sizeof(uint8_t), written_len, pipe);
  pclose(pipe);
  return 0; 
}