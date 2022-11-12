# What is hashing?

> The process of converting a key to an address(index of an array) is called hashing or key to address transformation and array in which insertion and searching is done through hashing is called _hash table_.

In hashing, we take a key as input and return the hash value of that key which is used as the address for storing the key in the array.

Keys may be of any type(`int`, `float`, etc), but the hash value will always be an integer.

$$Key \rightarrow HashFunction \rightarrow Address$$

**Collision occurs when the hash function generates the same address for different keys.**

_The keys which are mapped to the same address are called **synonyms**._

` When a given key is compared with many keys, then each comparison is known as a probe.`

```
The efficiency of a collision resolution technique is defined in terms of the number of probes required to find a record with a given key.
```

# Hash functions

> A hash function works like a mapping interface between the key and the hash table. 

**If the size of the hash table is _m_ then we need a hash function that can generate addresses in the range _0_ to _m-1_.**

## Methods for computing addresses from a key.

### 1. Truncation(or Extraction)
 > Here we take only a part of the key as address.
 > This method is easy, but chances of collision are more.

### 2. Midsquare method
> The key is squared and some digits or bits from the middle of this square are taken as address.
> Selection of digits depends on size of the table.
> Same number of digits should be selected from the squares of all the keys.

### 3. Folding method
> Key is broken into different parts where length each part is the same as the that of the required address(except possibly the last part).
> The address of the key can be obtained by ignoring the final carry in the sum.

### 4. Division method
> Key is divided by table size and the remainder is taken as the address for hash table.

If _m_ is the size of the hash table, then we will get the addresses in the range {0....m-1}.

If **H()** is a hash function for this method, **k** is a key and **m** is the size of the table, then **H()** is defined as:

$$H(k)=k\mod m$$

# Collision resolution

_There are two collision resolution techniques:_
1. Open addressing(Closed hashing).
2. Separate chaining(Open Hashing).

## 1. Open addressing(Closed hashing)
> The key which caused the collision is placed inside the has table itself but at a location other than its has address.

**There are 3 methods to search for an empty location:**

1. Linear probing.
2. Quadratic probing.
3. Double hashing.

### 1. Linear probing
> Collision keys are stored near the initial collision point.


**FORMULA:**
$$H(k, i) = (h(k) + i) \mod Tsize$$

`Tsize` is the size of the hash table; `i` varies from `0` to `Tsize-1`;

Where
$$h(k) = k\mod Tsize$$

### 2. Quadratic probing
> Collision keys are stored away from the initial collision point.


**FORMULA:**
$$H(k, i) = (h(k) + i^2) \mod Tsize$$

Where
$$h(k) = k\mod Tsize$$

> Quadratic probing gives secondary clustering problem.

**In secondary clustering, the keys that have the same hash address will probe the same sequence of locations.**

Example:

Consider the keys 46, 35 and 57.

Let's say the size of the hash table is 11, then `i` will go from _0_ to _10_.

$$H(46) = (h(46) + 0)\mod 11 = 2$$ [h(46) = $46\mod 11 = 2$ ]
$$H(46) = (h(46) + 1^2)\mod 11 = 3$$
$$H(46) = (h(46) + 2^2)\mod 11 = 6$$
$$H(46) = (h(46) + 3^2)\mod 11 = 0$$
$$ .... and so on$$

Similarly, for 35, we will get the same sequence of numbers and so for 57.

Because $47\mod 11 = 2$, $35\mod 11 = 2$ and $57\mod 11 = 2$, so the hash address for 47, 35 and 57 is 2; so the sequence of locations formed will also be same. This is **Secondary clustering**.

---
