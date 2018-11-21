$in = <>;
$idx = 0;
$sum = 0.0;
travel(0);
printf "%.2lf\n", $sum;

sub travel
{
	my ($depth) = @_;
	if(substr($in, $idx, 1) eq '(')
	{
		$idx++;
		travel($depth+1);
		$idx++;
		travel($depth+1);
		$idx++;
	}
	else
	{
		substr($in, $idx) =~ /(-?\d+)/;
		$sum += $1 / (2**$depth);
		$idx += length($1);
	}
}
