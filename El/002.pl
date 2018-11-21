while(<>)
{
	@ary = $_ =~ /(-?\d+)/g;
	foreach (@ary)
	{
		if($_ == -1)
		{
			$over = 1 and last if $idx;
			$idx = 1 and next;
		}
		if($idx)
		{
			if($hash{$_})
			{
				print $flag, $_;
				$flag = " " and $hash{$_} = 0;
			}
		}
		else
		{
			$hash{$_} = 1;
		}
	}
	last if $over;
}
print "empty" if !$flag;
print "\n";
