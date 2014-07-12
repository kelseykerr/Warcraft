//
//  Input_Handling.h
//  PA4
//
//  Created by Kelsey Kerr on 11/26/13.
//  Copyright (c) 2013 Kelsey Kerr. All rights reserved.
//

#ifndef PA4_Input_Handling_h
#define PA4_Input_Handling_h

class Invalid_Input{
    public :
    Invalid_Input (char * in_ptr): msg_ptr (in_ptr) { }
    const char * const msg_ptr;
    private :
    Invalid_Input ( ) ;
};


#endif
