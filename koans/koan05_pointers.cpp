/*
    Copyright (c) 2012 Torbjörn Klatt <opensource@torbjoern-klatt.de>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#include "../headers/koan05_pointers.hpp"

void Koan05_pointers::they_are_just_variables() {
  int an_int = 42;
  int *pointer_to_an_int = &an_int;
  ASSERT_EQUAL(*pointer_to_an_int, 42);
  ASSERT_EQUAL(pointer_to_an_int, &an_int);
}

void Koan05_pointers::they_are_really_just_variables() {
  int an_int = 42;
  int another_int = 21;
  int *pointer_to_an_int = &an_int;
  ASSERT_EQUAL(*pointer_to_an_int, 42);
  ASSERT_EQUAL(pointer_to_an_int, &an_int);
  pointer_to_an_int = &another_int;
  ASSERT_EQUAL(*pointer_to_an_int, 21);
  ASSERT_EQUAL(pointer_to_an_int, &another_int);
}

void Koan05_pointers::they_have_power() {
  int an_int = 42;
  int *powerful_pointer = &an_int;
  ASSERT_EQUAL(*powerful_pointer, 42);
  ASSERT_EQUAL(powerful_pointer, &an_int);
  *powerful_pointer = 21;
  ASSERT_EQUAL(an_int, 21);
  ASSERT_EQUAL(powerful_pointer, &an_int);
}

void Koan05_pointers::they_are_not_almighty() {
  /*const*/ int an_int = 42;
  /*const*/ int *wannabe_powerful = &an_int;
  ASSERT_EQUAL(*wannabe_powerful, 42);
  ASSERT_EQUAL(wannabe_powerful, &an_int);
  // Will this work? Think about it!
  // What do you need to change to make it work?
  *wannabe_powerful = 21;
  ASSERT_EQUAL(an_int, 21);
  ASSERT_EQUAL(wannabe_powerful, &an_int);
}

void Koan05_pointers::they_can_be_non_const_unlike_array_variables() {
  int array[4];
  int *pa = array;
  ASSERT_EQUAL(pa, &array[0]);

  pa = pa + 3;
  ASSERT_EQUAL(pa, &array[3]);
}

void Koan05_pointers::they_can_manipulate_arrays() {
  int array[4] = {1, 2, 3, 4};
  int *pa = array;
  ASSERT_EQUAL(*(pa + 2), 3);
}

void Koan05_pointers::they_can_be_assigned_addresses_and_pValues() {
  int b = 77;
  int *pA;
  int *pB = &b;
  pA = pB;
  // ASSERT_EQUAL(*pA, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(*pA, 77);
}

void Koan05_pointers::they_can_do_arithmetic_with_integers_only() {
  int a[10] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
  a[5] = {8901};
  int *ap = a;

  // Do the necessary pointer arithmetic with ap
  // and edit below
  // ASSERT_EQUAL(&a[5], THIS_IS_NOT_NULL);
  ASSERT_EQUAL(&a[5], ap + 5);

  // What is the value pointed to by ap before
  // and after the arithmetic?
  // ASSERT_EQUAL(*ap, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(*ap, 1);
  ap = ap + 5;
  // ASSERT_EQUAL(*ap, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(*ap, 8901);
  ap = ap + 1;
  // ASSERT_EQUAL(*ap, FILL_THE_NUMBER_IN);
  ASSERT_EQUAL(*ap, 2);
}

void Koan05_pointers::they_can_be_initialized_to_dynamic_memory() {
  char *p = 0;
  p = (char *)malloc(5 * sizeof(char));
  // ASSERT_EQUAL(p, THIS_IS_NOT_NULL);
  ASSERT_EQUAL(p, p);
}

void Koan05_pointers::they_can_be_used_to_access_dynamic_memory() {
  char *p = 0;
  p = (char *)malloc(5 * sizeof(char));
  *p = 'a';
  // ASSERT_EQUAL(*p, FILL_THE_CHAR_IN);
  ASSERT_EQUAL(*p, 'a');
}

// EOF
