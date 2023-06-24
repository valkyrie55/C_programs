with cte as (
  select modelname as Model Name, brand as Brand, source as Source, country as Country, 'Feature_1' as Topic,
  count(case when Feature_1 = -1 then 1 end) as Negative,
  count(case when Feature_1 = -1 then 1 end) as Negative,
  count(case when Feature_1 = -1 then 1 end) as Negative,
  )