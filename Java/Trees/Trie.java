/*
Approach for implementing a Trie ?
       1. Create a root node with the help of TrieNode() constructor.
       2. Store a collection of strings that have to be inserted in the trie in a Array of strings say, words.
       3. Inserting all strings in Trie with the help of the insert() function,
       4. Search strings with the help of search() function.
Insert operation :
* Every character of the input key is inserted as an individual Trie node.
  Note that the children is an array of pointers (or references) to next-level trie nodes.
* The key character acts as an index to the array children.
* If the input key is new or an extension of the existing key,
  construct non-existing nodes of the key, and mark the end of the word for the last node.
* If the input key is a prefix of the existing key in Trie, Simply mark the last node of the key as the end of a word.

Search Operation :
* Searching for a key is similar to the insert operation.
  However, It only compares the characters and moves down.
  The search can terminate due to the end of a string or lack of key in the trie.

* In the former case, if the isEndofWord field of the last node is true, then the key exists in the trie.
* In the second case, the search terminates without examining all the characters of the key,
  since the key is not present in the trie.

   */

//Implementation of Trie

package Java_practice.Trie;
import java.util.*;
public class Trie {
    static class Node{
        Node [] children=new Node[26];
        boolean end_of_word=false;
        Node(){
            for(int i=0;i<26;i++){
                children[i]=null;
            }
        }
    }

    public static Node root= new Node();

    //inserting the word in the Trie
    public static void insert(String word){
        Node current=root;
        for(int level=0;level<word.length();level++){
            int idx=word.charAt(level)-'a';
            if(current.children[idx]==null){
                current.children[idx]=new Node();
            }
            current=current.children[idx];
        }
        current.end_of_word=true;
    }
      //search the words in the trie
    public static boolean search(String key){
        Node current=root;
        for(int level=0;level<key.length();level++){
            int idx=key.charAt(level)-'a';
            if(current.children[idx]==null){
               return false;
            }
            current=current.children[idx];
        }
       return current.end_of_word==true;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String words[]={"the","a","there","their","any","thee"};

        // Here we take input from user if we want
        //        int size=sc.nextInt();
        //        String words[]=new String[size];
        //        for(int i=0;i<size;i++){
        //           words[i]=sc.next();
       //        }

        //inserting words into Trie
        for(int i=0;i< words.length;i++){
            insert(words[i] );
            System.out.println("word Inserted into trie = " + words[i]);
        }
        //Searching word into trie
        for(int i=0;i< words.length;i++){
            if(search(words[i])){
                System.out.println("word present");
            }else{
                System.out.println("word not present");
            }
        }
        // if we want to search individual word we can simply call the search function like this
            //System.out.println(search(words[word]) );
    }
}
