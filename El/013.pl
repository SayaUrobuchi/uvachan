while(<>)
{
	push @var_ary, $_ =~ /-?\d+/g;
}
$n = @var_ary[0];
foreach (0..$n-1)
{
	@{$ary[$_]} = sort {$b <=> $a} @var_ary[1+$_*3..3+$_*3];
}
for($i=0, $lim=scalar(@ary); $i<$lim; $i++)
{
	for($j=0; $j<$lim; $j++)
	{
		if($ary[$i][0] > $ary[$j][0] && $ary[$i][1] > $ary[$j][1] &&
				$ary[$i][2] > $ary[$j][2])
		{
			push @{$map[$i]}, $j;
		}
	}
}
$res = $n;
for($i=0; $i<$lim; $i++)
{
	@used = ();
	$res -= match($i);
}
print $res, "\n";

sub match
{
	my $now = $_[0], $i;
	if($used[$now])
	{
		return 0;
	}
	$used[$now] = 1;
	foreach $i (@{$map[$now]})
	{
		if(!$used[$i+1000])
		{
			$used[$i+1000] = 1;
			if(!$mat[$i] || match($mat[$i]))
			{
				$mat[$i] = $now;
				return 1;
			}
		}
	}
	return 0;
}
