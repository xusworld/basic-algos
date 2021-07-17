#ifndef BASIC_ALGOS_ALGOS_UTIL_H_
#define BASIC_ALGOS_ALGOS_UTIL_H_

namespace algo {

#define DELETE_COPY_CTOR(class_name)        \
  class_name(const class_name&) = delete;   \
  class_name& operator=(const class_name&) = delete

#define DELETE_MOVE_CTOR(class_name)   \
  class_name(class_name&&) = delete;   \
  class_name& operator=(class_name&&) = delete

#define DELETE_COPY_AND_MOVE_CTOR(class_name) \
  DELETE_COPY_CTOR(class_name);               \
  DELETE_MOVE_CTOR(class_name)



} // namespace algo


#endif //BASIC_ALGOS_ALGOS_UTIL_H_
