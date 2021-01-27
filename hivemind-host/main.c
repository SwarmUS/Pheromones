#include <message.pb.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint16_t s_bufferSize = 1024;

int main_encode_decode() {
  /* This is the buffer where we will store our message. */
  uint8_t bufferSend[s_bufferSize];
  uint8_t bufferReceive[s_bufferSize];
  bool status;

  // stream definition
  pb_ostream_t outputStream = pb_ostream_from_buffer(bufferSend, s_bufferSize);
  pb_istream_t inputStream =
      pb_istream_from_buffer(bufferReceive, s_bufferSize);

  /*-------- SENDER -------*/
  // Packet definition
  FunctionArgument arg = {};
  arg.which_argument = FunctionArgument_int_arg_tag;
  arg.argument.int_arg = 10;

  FunctionCallRequest f_req = FunctionCallRequest_init_default;
  f_req.arguments_count = 1;
  f_req.arguments[0] = arg;
  strcpy(f_req.function_name, "hello_world");

  Request req = Request_init_default;
  req.id = 1;
  req.which_message = Request_function_call_tag;
  req.message.function_call = f_req;

  Message msg = Message_init_default;
  msg.which_message = Message_request_tag;
  msg.message.request = req;

  // send message on the wire
  status = pb_encode(&outputStream, Message_fields, &msg);
  printf("Sending status: %d \n", status);

  // Copying to mimic sending over the wire (tcp, uart, spi, etc)
  memcpy(bufferReceive, bufferSend, s_bufferSize);

  /*-------- RECEIVER -------*/
  Message msg_receive = Message_init_default;
  strcpy(msg_receive.message.request.message.function_call.function_name,
         "GARBAGE STUFSDFSSSSSSSSSSSSSSSSSSSS");
  status = pb_decode(&inputStream, Message_fields, &msg_receive);
  printf("Receiving status status: %d \n", status);

  printf("VALUE: %s \n",
         msg_receive.message.request.message.function_call.function_name);

  printf("end\n");
  return 0;
}

int main_pipe_data() {
  /* This is the buffer where we will store our message. */
  uint8_t bufferSend[s_bufferSize];
  uint8_t bufferReceive[s_bufferSize];
  uint8_t bufferSend2[s_bufferSize];
  uint8_t bufferReceive2[s_bufferSize];
  bool status;

  // stream definition
  pb_ostream_t outputStream = pb_ostream_from_buffer(bufferSend, s_bufferSize);
  pb_istream_t inputStream =
      pb_istream_from_buffer(bufferReceive, s_bufferSize);

  pb_ostream_t outputStream2 = 
      pb_ostream_from_buffer(bufferSend2, s_bufferSize);
  pb_istream_t inputStream2 =
      pb_istream_from_buffer(bufferReceive2, s_bufferSize);

  /*-------- SENDER -------*/
  return 0;
}

int main() { return main_encode_decode(); }
