//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#include "Rolodex.h"

Rolodex::Rolodex()
{
    // Add code here
    sentinel = Item.value;
    sentinel -> next = sentinel;
    sentinel -> prev = sentinel;
    current = sentinel;
}

/**
 * Returns true if the Rolodex is positioned before the first card.
 */
bool Rolodex::isBeforeFirst() const
{
    // Replace with real code
    return (sentinel == current);
}

/**
 * Returns true if the Rolodex is positioned after the last card.
 */
bool Rolodex::isAfterLast() const
{
    // Replace with real code
    return (sentinel == current);
}

/**
 * Rotates the Rolodex one card forwards.
 */
void Rolodex::rotateForward()
{
    // Add code here
    current = current->next;
}

/**
 * Rotates the Rolodex one card backwards.
 */
void Rolodex::rotateBackward()
{
    // Add code here
    current = current->prev;
}

/**
 * Returns the value of the current card.
 */
const std::string& Rolodex::currentValue() const
{
    // Temporary hack to keep the compiler happy
    // Replace both lines with real code
//    static std::string dummy;
//    return dummy;
	
	return current->value;

}

/**
 * Inserts a new card after the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertAfterCurrent(const std::string& value)
{
    // Add code here
    Item* coming = new Item;
    
    coming->value = value;
    coming->next = current->next;
    coming->prev = current;
    current->next->prev = coming;
    current->next = coming;
    current = coming;
    
}

/**
 * Inserts a new card before the current card and positions the Rolodex
 * at the newly inserted card.
 *
 * @param value The value to insert into a new card.
 */
void Rolodex::insertBeforeCurrent(const std::string& value)
{
    // Add code here
    Item* going = new Item;

        going -> value = value;
        going -> next = current;
        going -> prev = current-> prev;
        current-> prev -> next = going;
        current-> prev = going;

        current=going;
    
}
