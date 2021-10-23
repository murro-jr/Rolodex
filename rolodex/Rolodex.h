//
// COMP2711,8801 Computer Programming 2
// Flinders University
//

#ifndef ROLODEX_H
#define ROLODEX_H

#include <string>

class Rolodex {
public:
    /**
     * Creates a new empty Rolodex.
     */
    explicit Rolodex();

    /**
     * Returns true if the Rolodex is positioned before the first card.
     */
    bool isBeforeFirst() const;

    /**
     * Returns true if the Rolodex is positioned after the last card.
     */
    bool isAfterLast() const;

    /**
     * Rotates the Rolodex one card forwards.
     */
    void rotateForward();

    /**
     * Rotates the Rolodex one card backwards.
     */
    void rotateBackward();

    /**
     * Returns the value of the current card.
     */
    const std::string& currentValue() const;
    /**
     * Inserts a new card after the current card and positions the Rolodex
     * at the newly inserted card.
     *
     * @param value The value to insert into a new card.
     */
    void insertAfterCurrent(const std::string& value);

    /**
     * Inserts a new card before the current card and positions the Rolodex
     * at the newly inserted card.
     *
     * @param value The value to insert into a new card.
     */
    void insertBeforeCurrent(const std::string& value);

    /**
     * Delete the value of the current card.
     */
    void delete_current();

private:
    // Add instance variables here
    struct RodolexItem {
        std::string value_;
        RodolexItem* next_;
        RodolexItem* prev_;
    };

    RodolexItem* sentinel;
    RodolexItem* current;

};

#endif //ROLODEX_H
