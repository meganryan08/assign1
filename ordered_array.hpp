/*
 * ordered_array.hpp
 * Definition of the ordered_array class. You can either create a separate 
 * ordered_array.cpp and put the method definitions there, or replace the 
 * method declarations below with definitions. E.g., replace
 *
 *     int sz();
 *
 * with 
 * 
 *     int sz() 
 *     {
 *         // Your code here...
 *     }
 *
 * and similarly for all the other functions
 */
 #include <iostream>
 #include <stdexcept>
 using namespace std; 

class ordered_array {
  public:
    /* constructor
       Construct a new ordered_array with the given cap (maximum sz).
       The sz of a new ordered_array should be 0.
    */
    ordered_array(int cap) : sz(0), cap(cap) {
      data = new int[cap]; 
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
    ordered_array(const ordered_array& original) : sz(original.sz), cap(original.cap) {
      data = new int[cap];
      for(int i = 0; i < original.sz; i++) {
         data[i] = original.data[i];
      }
    }

    /* sz()
       Returns the sz (number of elements in the array).
    */
    int size() const {
      return sz;
    }

    /* cap()
       Returns the maximum sz of the array.
    */
    int capacity() const {
      return cap;
    }

    /* insert(e)
       Insert e into the array. Note that it is OK to insert duplicates; if n 
       copies of a value are inserted into the array then n copies should appear
       in the array.

       If sz() == cap() then this does nothing.

       If e == -2147483648 then this does nothing (i.e., -2147483648 is not a
       valid value to insert).
    */
    void insert(int elem) {
       if (sz == cap || elem == -2147483648) {
       return;
      }

      if(sz == cap) {
         return;
      }
      //check elements from end and shift
      int i = sz-1;
      while(i >= 0 && data[i] > elem) {
         data[i+1] = data[i]; // copies/shifts greater value into next slot
         i--;
      }
      data[i+1] = elem;
      sz++; //have to update sz after adding element!

    }

    /* remove(e)
       Remove e from the array, if it exists. (If it does not exist, the
       array should be unchanged.) If multiple copies of e are present, only
       one should be removed.

       If e = -2147483648 then this does nothing.
    */
    void remove(int elem) {
      if(elem == -2147483648)
         return;

      for(int i = 0; i < sz; i++) {
         if(data[i] == elem) {
            for(int j = i; j < sz-1; j++) {
               data[j] = data[j+1];
            }

            --sz;
            return;
         }
      }
    }

    /* exists(e)
       Returns true if e is present at least once in the array.

       If e == -2147483648 then this returns false.
    */
    bool exists(int elem) {
      if(elem == -2147483648)
         return false;

      for(int i=0; i< sz; i++) {
         if(data[i] == elem) {
         return true;
         }
      }

      return false;
   }

    /* at(i)
       Returns a *reference* to the element at index i. If i < 0 or i >= sz(),
       then the function should throw a std::out_of_range exception (this is the
       same exception that std::vector::at would throw in this situation).

       Note that at() should *never* return -2147483648.
    */
    int& at(int i) {
      if( i < 0 || i >= sz) {
         throw std::out_of_range("Invalid Index");
      }

      return data[i];
    }

  private:
   int* data;
   int sz;
   int cap;
};
