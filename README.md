# Rolodex

A  basic  version  of  the  program  that  includes  a  skeleton Rolodex  class  is  provided. The  class  has  methods  for  rotating the Rolodex forwards and backwards, for returning the value of the card at the current position, and for inserting a new card either before or after the current card.The initial version of the program implements the basic sorting algorithm, which is a modified version of insertion sort (it is consequently not very efficient). In addition, it supports a command line processing mechanism that allows you to run  the  program  with  options.  The  initial  version  recognises  two  options: -v  (verbose)  and -c  (current).  The verboseoption  causes  the  actions  of  the  Rolodex  to  be  reported  as  they  occur,  which  might  be  useful  when  debugging,  whilst  the current option causes the program to print only the current card’s value rather than all card values. 

Since you do not know how many entries the Rolodex will hold, you will need to use dynamically allocated memory to store the information. An easy way to implement the Rolodex file is using a doubly linked list. Each item in the list will store the information for a single card and will need an instance variable to store the card value as well as pointers to the next and previous items. For example, you could represent the items like this: 

struct RolodexItem {     
std::string value_;     
RolodexItem* next_;     
RolodexItem* prev_; 
}; 

You will also need some way of knowing when you have reached the beginning or end of the Rolodex. One strategy is to use a circular list with a sentinel value that marks both the beginning and the end. This approach will considerably simplify the management of the links when items are inserted or removed. 

Level 1: Basic operationComplete  the  implementation  of Rolodex  so  that  all  the  methods  work  correctly. The  insert  methods  should  leave  the Rolodex positioned so that the current item is the one just inserted. 

Level 2: No duplicatesModify the program so that the command line option -d (no duplicates) causes a new item to be inserted only if the item is not already present in the Rolodex. For example, if the input consisted of the text far far far away then the output would contain only two lines away far

Level 3: DeletionModify the program such that an input string that begins with a - causes that word (without the -) to be deleted from the Rolodex instead of inserted. For example, if the input is the quick black fox jumps -black brown over the lazy dogthen the output would contain the word brown but not black. Deleting  a  word  should  be  implemented  by  moving  the  Rolodex  to  the  position  where  the  word  would  normally  be inserted, but then deleting the current item if it matches the word (if it does not match, no action is performed). You will need  to  add  a  method  to  the  Rolodex  class  that  deletes  the  current  item  and  leaves  the  Rolodex  positioned  so  that  the current  item  is  the  one following  the  deleted  item  if  there  is  a  following  item,  or  the  item preceding  the  deleted  item otherwise. Hint: as part of your solution, consider the case where the input word is a - (i.e., a dash). 

Level 4: ReportModify  the  program  so  that  if  it  is  run  with  the  command  line  option -r  (report),  it  outputs  a  report  of  the  Rolodex operations  rather  than  the  words  themselves.  The  report  should  consist  of  the  following  integer  values  separated  by spaces: the number of items inserted, the number of duplicate items omitted (expected to be 0 unless the -d option is in effect), the number of items deleted, the number of times the rotateForward operation was performed, and the number of times the rotateBackward operation was performed. For example, if the input consisted of the text the quick brown fox jumps over the lazy dogthen the output should read 

9 0 0 5 8

The report indicates that there were 9 words inserted, 0 duplicate words omitted, 0 words deleted, and that a total of 5 forward rotations and 8 backward rotations of the Rolodex were performed. However, if the -d option is in effect for the same input, the output should instead read 8 1 0 5 8In this case, the report indicates that there were 8 words inserted, 1 duplicate word omitted (the second occurrence of the), 0 words deleted, 5 forward rotations, and 8 backward rotations.




 
