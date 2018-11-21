chomp ($in = <>);
%tbl = ("]", "[", "}", "{", ">", "<", ")", "(", 
		"[", "!", "{", "!", "(", "!", "<", "!");
for($i=0, $lim=length($in); $i<$lim; $i++)
{
	$tar = substr $in, $i, 1;
	if($tbl{$tar} eq "!")
	{
		push @stack, $tar;
	}
	else
	{
		if(!scalar(@stack) or ($stack[$#stack] ne $tbl{$tar}))
		{
			last;
		}
		pop @stack;
	}
}
print !scalar(@stack) && $i >= $lim ? "YES\n" : "NO\n";
