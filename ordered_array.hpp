/*
 * ordered_array.hpp
 * Definition of the ordered_array class. You can either create a separate 
 * ordered_array.cpp and put the method definitions there, or replace the 
 * method declarations below with definitions. E.g., replace
 *
 *     int size();
 *
 * with 
 * 
 *     int size() 
 *     {
 *         // Your code here...
 *     }
 *
 * and similarly for all the other functions
 */

class ordered_array {
  public:
    /* constructor
       Construct a new ordered_array with the given capacity (maximum size).
       The size of a new ordered_array should be 0.
    */
    ordered_array(int cap) : size(0), capacity(cap) {
      data = new int[capacity]; 
    }; 
      
    /* destructor
       Note that you only need a destructor if you're using a dynamic array.
       If you're using a vector, you should delete or comment this out.
    */
    ~ordered_array() {
      delete[]data;
    }

    /* This assignment does not require you to implement the copy constructor
       or copy assignment operator, even if you are using dynamic memory.
    */
    ordered_array(const ordered_array& original) : size(original.size), cpacity(original.capacity) {
      data = new int[capacity];
      for(int i = 0; i < original.size; i++) {
         data[i] = orginal.data[i];
      }
    }

    /* size()
       Returns the size (number of elements in the array).
    */
    int get_size() const {
      return size;
    }

    /* capacity()
       Returns the maximum size of the array.
    */
    int get_capacity() const {
      return capacity;
    }

    /* insert(e)
       Insert e into the array. Note that it is OK to insert duplicates; if n 
       copies of a value are inserted into the array then n copies should appear
       in the array.

       If size() == capacity() then this does nothing.

       If e == -2147483648 then this does nothing (i.e., -2147483648 is not a
       valid value to insert).
    */
    void insert(int elem) {
      if(size == capacity) {
         return
      }
      //check elements from end and shift
      int i = size-1;
      while(i >= 0 && data[i] > elem) {
         data[i+1] = data[i]; // copies/shifts greater value into next slot
         i--;
      }
      data[i+1] = elem;
      size++; //have to update size after adding element!

    }

    /* remove(e)
       Remove e from the array, if it exists. (If it does not exist, the
       array should be unchanged.) If multiple copies of e are present, only
       one should be removed.

       If e = -2147483648 then this does nothing.
    */
    void remove(int elem) {
      for(int i = 0; i<size ; i++) {
            if(data[i] == elem) {
            data[i] = data[i+1];
         }
         else if()
         return;
      }
      size--; //decrement size 
    }

    /* exists(e)
       Returns true if e is present at least once in the array.

       If e == -2147483648 then this returns false.
    */
    bool exists(int elem);

    /* at(i)
       Returns a *reference* to the element at index i. If i < 0 or i >= size(),
       then the function should throw a std::out_of_range exception (this is the
       same exception that std::vector::at would throw in this situation).

       Note that at() should *never* return -2147483648.
    */
    int& at(int i);

  private:
   int* data;
   int size;
   int capacity;
};
