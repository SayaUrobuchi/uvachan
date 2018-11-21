while(<>)
{
	push(@in_vars, $_ =~ /-?\d+/g);
}
($n, $m, $o) = @in_vars[0..2];
for($i=3; $o--; $i+=2)
{
	($p, $q) = @in_vars[$i, $i+1];
	push @{$map{$p}}, $q;
}
$res = 0;
foreach $i (keys %map)
{
	%used = ();
	if(find($i))
	{
		$res++;
	}
}
print $res, "\n";
foreach $i (keys %mat)
{
	printf ("%d %d\n", $mat{$i}, $i) if exists $mat{$i};
}

sub find
{
	my ($now) = @_;
	my $i;
	if(exists $used{$now})
	{
		return 0;
	}
	$used{$now} = 1;
	foreach $i (@{$map{$now}})
	{
		if(mat($now, $i))
		{
			return 1;
		}
	}
	return 0;
}

sub mat
{
	my ($tar, $now) = @_;
	if(exists $used{$now+1500})
	{
		return 0;
	}
	$used{$now+1500} = 1;
	if(!exists($mat{$now}) || find($mat{$now}))
	{
		$mat{$now} = $tar;
		return 1;
	}
	return 0;
}
