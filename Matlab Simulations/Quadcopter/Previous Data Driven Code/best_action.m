function action_val=best_action(val,q)
if (107>=val) && (val>97)
    [~,action_val]=max(q(:,1),[],1);
elseif (97>=val) && (val>79)
    [~,action_val]=max(q(:,2),[],1);
elseif (79>=val) && (val>60)
    [~,action_val]=max(q(:,3),[],1);
elseif (60>=val) && (val>47)
    [~,action_val]=max(q(:,4),[],1);
elseif (47>=val) && (val>34)
    [~,action_val]=max(q(:,5),[],1);
elseif (34>=val) && (val>24);
    [~,action_val]=max(q(:,6),[],1);
elseif (24>=val) && (val>14)
    [~,action_val]=max(q(:,7),[],1);
elseif (14>=val) && (val>=11)
    [~,action_val]=max(q(:,8),[],1);
else
    action_val=4;
end