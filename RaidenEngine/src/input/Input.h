#ifndef INPUT_H
#define INPUT_H

#include "Window.h"

#define RAIDEN_KEY_UNKNOWN        GLFW_KEY_UNKNOWN            
#define RAIDEN_KEY_SPACE          GLFW_KEY_SPACE              
#define RAIDEN_KEY_APOSTROPHE     GLFW_KEY_APOSTROPHE         
#define RAIDEN_KEY_COMMA          GLFW_KEY_COMMA              
#define RAIDEN_KEY_MINUS          GLFW_KEY_MINUS              
#define RAIDEN_KEY_PERIOD         GLFW_KEY_PERIOD             
#define RAIDEN_KEY_SLASH          GLFW_KEY_SLASH              
#define RAIDEN_KEY_0              GLFW_KEY_0                  
#define RAIDEN_KEY_1              GLFW_KEY_1                  
#define RAIDEN_KEY_2              GLFW_KEY_2                  
#define RAIDEN_KEY_3              GLFW_KEY_3                  
#define RAIDEN_KEY_4              GLFW_KEY_4                  
#define RAIDEN_KEY_5              GLFW_KEY_5                  
#define RAIDEN_KEY_6              GLFW_KEY_6                  
#define RAIDEN_KEY_7              GLFW_KEY_7                  
#define RAIDEN_KEY_8              GLFW_KEY_8                  
#define RAIDEN_KEY_9              GLFW_KEY_9                  
#define RAIDEN_KEY_SEMICOLON      GLFW_KEY_SEMICOLON          
#define RAIDEN_KEY_EQUAL          GLFW_KEY_EQUAL              
#define RAIDEN_KEY_A              GLFW_KEY_A                  
#define RAIDEN_KEY_B              GLFW_KEY_B                  
#define RAIDEN_KEY_C              GLFW_KEY_C                  
#define RAIDEN_KEY_D              GLFW_KEY_D                  
#define RAIDEN_KEY_E              GLFW_KEY_E                  
#define RAIDEN_KEY_F              GLFW_KEY_F                  
#define RAIDEN_KEY_G              GLFW_KEY_G                  
#define RAIDEN_KEY_H              GLFW_KEY_H                  
#define RAIDEN_KEY_I              GLFW_KEY_I                  
#define RAIDEN_KEY_J              GLFW_KEY_J                  
#define RAIDEN_KEY_K              GLFW_KEY_K                  
#define RAIDEN_KEY_L              GLFW_KEY_L                  
#define RAIDEN_KEY_M              GLFW_KEY_M                  
#define RAIDEN_KEY_N              GLFW_KEY_N                  
#define RAIDEN_KEY_O              GLFW_KEY_O                  
#define RAIDEN_KEY_P              GLFW_KEY_P                  
#define RAIDEN_KEY_Q              GLFW_KEY_Q                  
#define RAIDEN_KEY_R              GLFW_KEY_R                  
#define RAIDEN_KEY_S              GLFW_KEY_S                  
#define RAIDEN_KEY_T              GLFW_KEY_T                  
#define RAIDEN_KEY_U              GLFW_KEY_U                  
#define RAIDEN_KEY_V              GLFW_KEY_V                  
#define RAIDEN_KEY_W              GLFW_KEY_W                  
#define RAIDEN_KEY_X              GLFW_KEY_X                  
#define RAIDEN_KEY_Y              GLFW_KEY_Y                  
#define RAIDEN_KEY_Z              GLFW_KEY_Z                  
#define RAIDEN_KEY_LEFT_BRACKET   GLFW_KEY_LEFT_BRACKET       
#define RAIDEN_KEY_BACKSLASH      GLFW_KEY_BACKSLASH          
#define RAIDEN_KEY_RIGHT_BRACKET  GLFW_KEY_RIGHT_BRACKET      
#define RAIDEN_KEY_GRAVE_ACCENT   GLFW_KEY_GRAVE_ACCENT       
#define RAIDEN_KEY_WORLD_1        GLFW_KEY_WORLD_1            
#define RAIDEN_KEY_WORLD_2        GLFW_KEY_WORLD_2            
#define RAIDEN_KEY_ESCAPE         GLFW_KEY_ESCAPE             
#define RAIDEN_KEY_ENTER          GLFW_KEY_ENTER              
#define RAIDEN_KEY_TAB            GLFW_KEY_TAB                
#define RAIDEN_KEY_BACKSPACE      GLFW_KEY_BACKSPACE          
#define RAIDEN_KEY_INSERT         GLFW_KEY_INSERT             
#define RAIDEN_KEY_DELETE         GLFW_KEY_DELETE             
#define RAIDEN_KEY_RIGHT          GLFW_KEY_RIGHT              
#define RAIDEN_KEY_LEFT           GLFW_KEY_LEFT               
#define RAIDEN_KEY_DOWN           GLFW_KEY_DOWN               
#define RAIDEN_KEY_UP             GLFW_KEY_UP                 
#define RAIDEN_KEY_PAGE_UP        GLFW_KEY_PAGE_UP            
#define RAIDEN_KEY_PAGE_DOWN      GLFW_KEY_PAGE_DOWN          
#define RAIDEN_KEY_HOME           GLFW_KEY_HOME               
#define RAIDEN_KEY_END            GLFW_KEY_END                
#define RAIDEN_KEY_CAPS_LOCK      GLFW_KEY_CAPS_LOCK          
#define RAIDEN_KEY_SCROLL_LOCK    GLFW_KEY_SCROLL_LOCK        
#define RAIDEN_KEY_NUM_LOCK       GLFW_KEY_NUM_LOCK           
#define RAIDEN_KEY_PRINT_SCREEN   GLFW_KEY_PRINT_SCREEN       
#define RAIDEN_KEY_PAUSE          GLFW_KEY_PAUSE              
#define RAIDEN_KEY_F1             GLFW_KEY_F1                 
#define RAIDEN_KEY_F2             GLFW_KEY_F2                 
#define RAIDEN_KEY_F3             GLFW_KEY_F3                 
#define RAIDEN_KEY_F4             GLFW_KEY_F4                 
#define RAIDEN_KEY_F5             GLFW_KEY_F5                 
#define RAIDEN_KEY_F6             GLFW_KEY_F6                 
#define RAIDEN_KEY_F7             GLFW_KEY_F7                 
#define RAIDEN_KEY_F8             GLFW_KEY_F8                 
#define RAIDEN_KEY_F9             GLFW_KEY_F9                 
#define RAIDEN_KEY_F10            GLFW_KEY_F10                
#define RAIDEN_KEY_F11            GLFW_KEY_F11                
#define RAIDEN_KEY_F12            GLFW_KEY_F12                
#define RAIDEN_KEY_F13            GLFW_KEY_F13                
#define RAIDEN_KEY_F14            GLFW_KEY_F14                
#define RAIDEN_KEY_F15            GLFW_KEY_F15                
#define RAIDEN_KEY_F16            GLFW_KEY_F16                
#define RAIDEN_KEY_F17            GLFW_KEY_F17                
#define RAIDEN_KEY_F18            GLFW_KEY_F18                
#define RAIDEN_KEY_F19            GLFW_KEY_F19                
#define RAIDEN_KEY_F20            GLFW_KEY_F20                
#define RAIDEN_KEY_F21            GLFW_KEY_F21                
#define RAIDEN_KEY_F22            GLFW_KEY_F22                
#define RAIDEN_KEY_F23            GLFW_KEY_F23                
#define RAIDEN_KEY_F24            GLFW_KEY_F24                
#define RAIDEN_KEY_F25            GLFW_KEY_F25                
#define RAIDEN_KEY_KP_0           GLFW_KEY_KP_0               
#define RAIDEN_KEY_KP_1           GLFW_KEY_KP_1               
#define RAIDEN_KEY_KP_2           GLFW_KEY_KP_2               
#define RAIDEN_KEY_KP_3           GLFW_KEY_KP_3               
#define RAIDEN_KEY_KP_4           GLFW_KEY_KP_4               
#define RAIDEN_KEY_KP_5           GLFW_KEY_KP_5               
#define RAIDEN_KEY_KP_6           GLFW_KEY_KP_6               
#define RAIDEN_KEY_KP_7           GLFW_KEY_KP_7               
#define RAIDEN_KEY_KP_8           GLFW_KEY_KP_8               
#define RAIDEN_KEY_KP_9           GLFW_KEY_KP_9               
#define RAIDEN_KEY_KP_DECIMAL     GLFW_KEY_KP_DECIMAL         
#define RAIDEN_KEY_KP_DIVIDE      GLFW_KEY_KP_DIVIDE          
#define RAIDEN_KEY_KP_MULTIPLY    GLFW_KEY_KP_MULTIPLY        
#define RAIDEN_KEY_KP_SUBTRACT    GLFW_KEY_KP_SUBTRACT        
#define RAIDEN_KEY_KP_ADD         GLFW_KEY_KP_ADD             
#define RAIDEN_KEY_KP_ENTER       GLFW_KEY_KP_ENTER           
#define RAIDEN_KEY_KP_EQUAL       GLFW_KEY_KP_EQUAL           
#define RAIDEN_KEY_LEFT_SHIFT     GLFW_KEY_LEFT_SHIFT         
#define RAIDEN_KEY_LEFT_CONTROL   GLFW_KEY_LEFT_CONTROL       
#define RAIDEN_KEY_LEFT_ALT       GLFW_KEY_LEFT_ALT           
#define RAIDEN_KEY_LEFT_SUPER     GLFW_KEY_LEFT_SUPER         
#define RAIDEN_KEY_RIGHT_SHIFT    GLFW_KEY_RIGHT_SHIFT        
#define RAIDEN_KEY_RIGHT_CONTROL  GLFW_KEY_RIGHT_CONTROL      
#define RAIDEN_KEY_RIGHT_ALT      GLFW_KEY_RIGHT_ALT          
#define RAIDEN_KEY_RIGHT_SUPER    GLFW_KEY_RIGHT_SUPER        
#define RAIDEN_KEY_MENU           GLFW_KEY_MENU               
#define RAIDEN_KEY_LAST           GLFW_KEY_LAST               

namespace Raiden {

	class Input {
		public:
			static void init(Window *w);
			static bool keyDown(int keycode);
		private:
			static Window *window;
	};

}

#endif
