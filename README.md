# C_Lib
C Library to simplify use multiple things

## Description
This library is composed of multiples mudules that i build when i need them. Each of the module is independent (except if the opposite isn't say in it's part) and has it's own git branch.

# Linked_List
This Module allow you to easily use linked list.

## Usage
All you need to do in order to use it is creating your structure with the library one in it like so :
```C
struct example {
    /* Your Datas */

    struct linked_list head;
    /* OR */
    linked_list_t head;
};
```

Make sure to replace ``<field_name>`` by whatever you want.  
Once this is done, call the function you need by sending :  
* A pointer to your structure (Here a ``struct example *``) when ``element``, ``list``, ``add`` or ``del`` is asked.
* The name of your field (Here ``head``) when ``field`` is asked
* An ``int`` (for exemple ``5``) just like you would do with a tab when ``idx`` is asked   

Warning, this lib DOES NOT (yet) ``free`` your structure. In order to do so, here is a function you can use :
```C
void free_my_list(struct example *my_list)
{
    for (struct example *next = NULL; my_list != NULL; my_list = next) {
        next = list_next(my_list, head);

        /* Free datas that are in your structure*/

        free(my_list);
    }
    return;
}
```



# Epitech Students
You are free to use this library as you want. A special branch has been created in which the [Epitech][Epitech_WebSite] [Coding Style][Epitech_WebSite] will be respected. I don't hav time to check new [Coding Style][Epitech_CodingStyle] every years. If you find a norm error, please fix it and send a ``pull request`` or, if you can't figure how to fix it, message me with the **file(s)**, **line(s)**  and **type(s)** of error(s).  

## Disclaimer
Warning. Some modules use standard library functions such as ``malloc`` or ``printf`` make sure these functions are allowed for your project. All functions used in each Module are available in the ``README`` of the module.   
I'm **not** responsible if you get flag for cheat beacause you use this library. You can use it but it will be at your own risks.

[Epitech_WebSite]: https://www.epitech.eu "Epitech Website"
[Epitech_CodingStyle]: https://intra.epitech.eu/file/public/technical-documentations/epitech_c_coding_style.pdf "Epitech Coding Style File"