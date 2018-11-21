$n = <>;
foreach $i (0..$n-1)
{
	$in = <>;
	@var_ary = $in =~ /[^\s]+/g;
	if($tbl{$var_ary[0]})
	{
		$inc = 1;
		last;
	}
	push @{$tbl{$var_ary[0]}}, @var_ary[2..$#var_ary];
}
if(!$inc)
{
	foreach $i (keys %tbl)
	{
		%used = ();
		if(travel($i))
		{
			$inc = 1;
			last;
		}
	}
}
print $inc ? "NOT CORRECT\n" : "CORRECT\n";

sub travel
{
	my $now = $_[0];
	my $i;
	$used{$now} = 1;
	foreach $i (@{$tbl{$now}})
	{
		if(!$used{$i})
		{
			if(travel($i))
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}
	$used{$now} = 0;
	return 0;
}
