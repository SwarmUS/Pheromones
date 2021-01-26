#ifndef __IPROTOBUFSTREAM_H_
#define __IPROTOBUFSTREAM_H_

#include <cstdint>

class IProtobufStream {

public:
  virtual ~IProtobufStream() = default;

  virtual bool receive(uint8_t *data, uint16_t length) = 0;
  virtual bool send(const uint8_t *data, uint16_t length) = 0;
}

#endif // __IPROTOBUFSTREAM_H_
