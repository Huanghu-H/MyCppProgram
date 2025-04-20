#include<iostream>
#include<cmath>
#include <algorithm>
#include <iterator>
#include <stdexcept>
using namespace std;
#include "byte_stream.hh"


ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

bool Writer::is_closed() const
{
  return ended_;
}

void Writer::push( string data )
{
	// 下面的是&data 
  size_t len = data.length();

  /* 有多少容量写多少数据 */
  if(remaining_capacity() < data.length())
    len = remaining_capacity();

  for(size_t i=0; i<len; i++)
    buf_.push_back(data[i]);

  nwrite_ += len;
  return ;
}

void Writer::close()
{
  ended_ = true; 
}

uint64_t Writer::available_capacity() const
{
  return buf_.size();
}

uint64_t Writer::bytes_pushed() const
{
  return nwrite_;
}

bool Reader::is_finished() const
{
  return ended_ && buf_.empty();
}

uint64_t Reader::bytes_popped() const
{
  return nread_;
}

string_view Reader::peek() const
{
	// 它说要输出多少字节了吗 
  if(len > buf_.size())
    return "";

  return string(buf_.begin(), buf_.begin()+len);
}

void Reader::pop( uint64_t len )
{
    if(len > buf_.size())
    return;

  for(size_t i=0; i<len; i++)
    buf_.pop_front();

  nread_ += len;
}

uint64_t Reader::bytes_buffered() const
{
  return nwrite_;
}

