%ifndef current_label
%define current_label 0
%endif 

%macro colon 2
    %if %0 = 3
        %ifid %2
             %2:
                dq current_label
                %define current_label %2        
        %else 
            %error "the label must be an identifier" 
        %endif 
        %ifstr %1
            db %1, 0        
        %else
            %error "the key must be a string value" 
        %endif
    %else 
        %error "the macro must take 2 arguments"
    %endif
%endmacro
