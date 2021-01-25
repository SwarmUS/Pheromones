#include <message.pb.h>
#include <pb_decode.h>
#include <pb_encode.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint16_t s_bufferSize = 1024;

void encode() {}

void decode() {}

int main() {
  /* This is the buffer where we will store our message. */
  uint8_t bufferSend[s_bufferSize];
  uint8_t bufferReceive[s_bufferSize];
  bool status;

  // stream definition
  pb_ostream_t outputStream = pb_ostream_from_buffer(bufferSend, s_bufferSize);
  pb_istream_t inputStream =
      pb_istream_from_buffer(bufferReceive, s_bufferSize);

  // Packet definition
  FunctionArgument arg = {};
  arg.which_argument = FunctionArgument_int_arg_tag;
  arg.argument.int_arg = 10;

  FunctionCallRequest f_req = FunctionCallRequest_init_default;
  f_req.arguments_count = 1;
  f_req.arguments[0] = arg;
  strcpy(f_req.functionName, "hello_world");

  Request req = Request_init_default;
  req.id = 1;
  req.which_message = Request_function_call_tag;
  req.message.function_call = f_req;

  Message msg = Message_init_default;
  msg.which_message = Message_request_tag;
  msg.message.request = req;

  // send message on the wire
  status = pb_encode(&outputStream, Message_fields, &msg);
  memcpy(bufferReceive, bufferSend, s_bufferSize); // "transfer over the wire"
  printf("Sending status: %d \n", status);

  // From the other side of the comm

  Message msg_receive = Message_init_default;
  status = pb_decode(&inputStream, Message_fields, &msg_receive);
  printf("Receiving status status: %d \n", status);

  printf("Funciton name: %s \n",
         msg_receive.message.request.message.function_call.functionName);

  return 0;
}
